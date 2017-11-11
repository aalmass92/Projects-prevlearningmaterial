#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


FILE *fp;

#define BUFSIZE 256


char buf[BUFSIZE];

int main (int argc, char *argv[])
{
  size_t rv;
  int i;
  
  if (argc == 4)
 fp = fopen (argv[3],"r");  
  else
 fp = fopen (argv[2],"r");
    
  if ( fp == NULL )
    {
      fprintf (stderr, "ERROR: fopen failed (%d, %s)\n", errno, strerror (errno));
    }

  rv = fread (buf, 1, BUFSIZE, fp);
  if ( rv<0 )
    {
      fprintf (stderr, "ERROR: fread failed (%d, %s)\n", errno, strerror (errno));
    }

  int j= 0;
  int k = 0;


   if ((strcmp(argv[1],"-32") == 0) && argc == 3){
  for ( i=0 ; i<rv ; i++ )
    {
      if ( i % 4 == 0 ){
	fprintf (stdout, "\n[%08x]: ", i);
	k++;
      }
      fprintf (stdout, "%08x ", buf[i]);
      j++;
    }
   }
    
  else if ((strcmp(argv[1],"-16") == 0 ) && argc == 3){
  for ( i=0 ; i<rv ; i++ )
    {
      if ( i % 4 == 0 ){
	fprintf (stdout, "[\n%04x]: ", i);
	k++;
      }
      fprintf (stdout, "%04x ", buf[i]);
      j++;
    }
    }
 

  else  if ((strcmp(argv[1],"-32") == 0) && (strcmp(argv[2],"-d") == 0) ){
  for ( i=0 ; i<rv ; i++ )
    {
      if ( i % 4 == 0 ){
	fprintf (stdout, "[\n%08d]: ", i);
	k++;
      }
      fprintf (stdout, "%08d ", buf[i]);
      j++;
    }
    }

  else  if ((strcmp(argv[1],"-16") == 0) && (strcmp(argv[2],"-d") == 0) ){
  for ( i=0 ; i<rv ; i++ )
    {
      if ( i % 4 == 0 ){
	fprintf (stdout, "[\n%04d]: ", i);
	k++;
      }
      fprintf (stdout, "%04d ", buf[i]);
      j++;
    }
    }

 printf("\nTotal Length: %d",(j * k));
   putchar ('\n');
}


