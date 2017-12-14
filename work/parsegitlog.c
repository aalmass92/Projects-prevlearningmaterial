#include <stdlib.h>
#include <stdio.h>

#define BUFLEN 256

int main (void)
{ 

  FILE *fp;
  char buf[BUFLEN];

  if  ( (fp = ("git log --raw","r")) == NULL)
    {
      fprint(stderr," Error opening file.");
      exit(1);

    }
  fgets(buf,BUFLEN, fp);

}
