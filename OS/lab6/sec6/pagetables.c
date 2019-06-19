/* read linux pagetables for a process, and show it 

compile:  gcc -g `getconf LFS_CFLAGS` -o pagetables pagetables.c
run as setuid root, chmod a+s

alternatively, this -may- work:
install: libcap2-bin
setcap  cap_sys_admin+ep pagetables 


using 

/proc/pid/pagemap
/proc/pid/maps
/proc/kpagecount
/proc/kpageflags

http://www.mjmwired.net/kernel/Documentation/vm/pagemap.txt
this is not useful http://www.eqware.net/Articles/CapturingProcessMemoryUsageUnderLinux/
http://www.tldp.org/LDP/tlk/mm/memory.html
https://www.kernel.org/doc/Documentation/vm/pagemap.txt

*/
#define _LARGEFILE64_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define PAGE_SIZE 4096 // getconf PAGE_SIZE

#define MAPBUFSIZE 100000
#define JUNKBUFSIZE 65536

FILE *fpout;


int pid;
char mapsfile[100];
char pgmapfile[100];
FILE *fpmap; // /proc does not like to be read buffered?
int fdmap;
int fdpag;
char mapbuf[MAPBUFSIZE];
char *pmapthis, *pmapnext, *pmapend;
unsigned long long *rbuf;
int pagesize;

unsigned long vm_start, vm_end, vm_pages, vm_pageno;

int
sleepforever ()
{
  fflush (fpout);
  while (1)
    sleep (1);

}


void
parse_map_line(char *mapl)
{
  int rv;
  rv = sscanf (mapl, "%lX-%lx", &vm_start, &vm_end);
  if ( rv != 2 )
    {
      fprintf (fpout,"Bad line %s\n", mapl);
      fflush (fpout);
      return;
    }
  vm_pages = (vm_end - vm_start)/PAGE_SIZE;
  vm_pageno = 0;
  if ( vm_pages > 0 )
    {
      off_t idx = (vm_start / pagesize) * 8; // 64 bits per entry
      off_t off;
      // fprintf (fpout, "Seeking to 0x%llX\n", (long long int) idx);
      off = lseek(fdpag, idx, SEEK_SET);
      if ( off != idx)
	{
	  fprintf (fpout, "seek() returned %lld seeking to %lld - %d(%s)\n", (long long int) off, (long long int) idx, errno, strerror(errno));
	  return;
	}
      while ( vm_pageno < vm_pages)
	{
	  unsigned long long pgdata;
	  rv = read (fdpag, &pgdata, 8);
	  if ( rv < 0 )
	    {
	      fprintf (fpout, "Can not read at offset %lld\n", (long long int) off);
	      return;
	    }
	  // if page is present, extract the PFN (counted in pages)
	  if (pgdata & 0x8000000000000000 )
	    {
	      unsigned long long pfn = pgdata & 0x003fffffffffffff;
	      fprintf (fpout, "%4lu: Virt 0x%016llx, Present 0x%016llx, Phys 0x%016llx\n", vm_pageno, (long long int) vm_start+vm_pageno*pagesize, pgdata, pfn * 4096);
	    }
	  else
	    {
	      fprintf (fpout, "%4lu: Empty %016llX\n", vm_pageno, pgdata);
	    }
	  vm_pageno++;
	}
    }
  fflush (fpout); // flush the buffers so it shows up on terminal
}
int
main (int argc, char *argv[])
{
  int i;
  int rv;
  if ( argc<2 )
    {
      pid = getpid();
    }
  else
    {
      pid = strtol(argv[argc-1],NULL,10);
    }
  fpout = stdout;
  pagesize = getpagesize ();
  fprintf (fpout, "Page size is %d\n", pagesize);
  if ( pagesize != PAGE_SIZE )
    {
      fprintf (fpout,"Unexpected page size %d\n", pagesize);
      exit (-1);
    }
  fprintf (fpout, "sizeof(off_t)=%u, sizeof(off64_t)=%u\n", sizeof(off_t), sizeof(off64_t));
  fprintf (fpout, "Decoding process %d\n", pid);
  // first, open the maps file
  sprintf (mapsfile, "/proc/%d/maps",pid);
#ifdef USEFP
  fpmap = fopen (mapsfile,"rb");
  if ( fpmap == NULL )
    {
      fprintf (fpout,"Failed to open %s\n", mapsfile);
      sleepforever ();
      exit (-1);
    }
#else
  fdmap = open (mapsfile,O_RDONLY);
  if ( fdmap <0 )
    {
      fprintf (fpout,"Failed to open %s\n", mapsfile);
      sleepforever ();
      exit (-1);
    }
#endif
  // open the pagemap file
  sprintf (pgmapfile, "/proc/%d/pagemap",pid);
  fdpag = open64 (pgmapfile,O_RDONLY);
  if ( fdpag<0 )
    {
      fprintf (fpout,"Failed to open %s\n", pgmapfile);
      sleepforever ();
      exit (-1);
    }
#ifdef USEFP
  // read the maps file, line by line
  while ( ! feof(fpmap))
    {
      memset (mapbuf, 0, MAPBUFSIZE);
      char *p = fgets (mapbuf, MAPBUFSIZE, fpmap);
      if ( p == NULL )
	{
	  fprintf (fpout,"Can not read maps file %d(%s)\n", errno, strerror(errno));
	  sleepforever();
	  exit (-1);
	}
      parse_map_line(mapbuf);
    }
#else
  rv = read (fdmap, mapbuf, MAPBUFSIZE);
  fprintf (fpout, "read %d bytes\n", rv);
  pmapthis = mapbuf;
  pmapend = mapbuf + rv;
  pmapnext = mapbuf;
  while (pmapthis)
    {
      // parse out single line, and position pointers to this line, and next line
      pmapnext = pmapthis;
      for ( i=0 ; i<rv ; i++ )
	{
	  if ( *pmapnext == '\0' || pmapnext >= pmapend)
	    {
	      // there is no next line
	      pmapnext = NULL;
	      break;
	    }
	  if ( *pmapnext == '\n' )
	    {
	      *pmapnext = '\0';
	      // there will be next line
	      pmapnext++;
	      break;
	    }
	  pmapnext++;
	}
      // parse this line
      fprintf (fpout, "\n/proc/pid/maps: %s\n", pmapthis);
      parse_map_line(pmapthis);
      pmapthis = pmapnext;
    }
#endif
  rbuf = malloc (JUNKBUFSIZE);
  unsigned long long total = 0;
  close (fdpag);
  // sudenly, this file never ends! kernel bug?
#ifdef READ_FOREVER
  // reopen the file
  fdpag = open64 (pgmapfile,O_RDONLY);
  if ( fdpag<0 )
    {
      fprintf (fpout,"Failed to open %s\n", pgmapfile);
      sleepforever ();
      exit (-1);
    }
  // lseek (fdpag, 0L, SEEK_SET);
  while (1)
    {
      fprintf (fpout, "Reading at offset %lld bytes\n", (long long int) lseek(fdpag, 0L, SEEK_CUR));
      rv = read (fdpag, rbuf, JUNKBUFSIZE);
      fprintf (fpout, "Read %d bytes from fdpag\n", rv);
      total += rv;
      if ( rv != JUNKBUFSIZE )
	break;
    }
  fprintf (fpout, "Total read %lld\n", total);
  free (rbuf);
  int realsize= total+4095;
  realsize &= ~0xfff;

  rbuf = malloc (realsize);
  close (fdpag);
  fdpag = open64 (pgmapfile,O_RDONLY);
  if ( fdpag<0 )
    {
    
  fprintf (fpout,"Failed to open %s\n", pgmapfile);
      sleepforever ();
      exit (-1);
    }
  rv = read (fdpag, rbuf, realsize);
  fprintf (fpout, "Read total %d bytes\n", rv);
  exit (0);
  // print first 10 64-bit values or so
  for ( i=0 ; i<10 ; i++ )
    fprintf (fpout, "%2d: %016llx\n", i, rbuf[i]);
  sleepforever();
#endif
}
