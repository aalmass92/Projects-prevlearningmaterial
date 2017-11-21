#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#define MAXNAMES 30000
#define MAXNAMELEN 80

FILE *fp;
char names[MAXNAMES][MAXNAMELEN];
char *pnames[MAXNAMES];
int namecount = 0;

void dump(void)
{
  int i;
  for (i = 0; i < namecount; i++)
    printf("%s", names[i]);
}

int main(int argc, char **argv)
{
  if( argc < 2 )
    {
      fprintf(stderr, "We need a parameter plz!\n");
      exit(-1);
    }
  fp = fopen(argv[1], "r");

  if ( fp == NULL )
    {
      fprintf(stderr, "Cannot open file %s (%d, %s)\n", argv[1], errno, strerror(errno));
      exit(-1);
    }

  while(namecount < MAXNAMES)
    {
      char *rv;
      rv = fgets (names[namecount], MAXNAMELEN, fp);
      if (rv == NULL)
	{
	  fprintf(stderr, "Cannot read file %s (%d, %s)\n", argv[1], errno, strerror(errno));
	  break;
	}
      if (names[namecount][0] == '\n' || names[namecount][0] == '\0')
	continue;
      namecount++;
    }
  int i;
  for (i = 0; i < namecount; i++)
    {
      pnames[i] = names[i];
    }

  //Now we can get down to some serious sorting
  clock_t cputime;
  cputime = clock();
  int swapcount;
  char *ptemp;
  do
    {
     
      /*     swapcount = 0;
      for(i = 0; i < namecount-1; i++)
	{
	  // fprintf(stderr, "line(%d): i=%d %s %s\n", __LINE__, i, pnames[i], pnames[i+1]);
	  if(strncmp(pnames[i], pnames[i + 1], MAXNAMELEN) > 0)
	    {
	      //  fprintf(stderr, "%s \n", pnames[i]);
	      ptemp = pnames[i];
	      pnames[i] = pnames[i+1];
	      pnames[i+1] = ptemp;	      
	      swapcount++;
	    }
      */

      qsort(*pnames[0], namecount,80, cmpfunc);

    }


}
  while(swapcount);
  cputime = clock() - cputime;
  float fcputime = (float) cputime / (float) CLOCKS_PER_SEC;
  printf("Total name count is %d\nTotal time elapsed %f\n", namecount, fcputime);
  
}


