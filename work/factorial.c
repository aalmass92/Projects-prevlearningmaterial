#include <stdio.h>
#include <stdlib.h>

int fact_r ( int n)
{
  if (n > 1)
    return n * fact_r(n-1);
  else
    return 1;
}


int
main ( int argc, char **argv)
{

  int i = 0, outcome;

  i = strtol(argv[1], NULL, 10);
 outcome = fact_r(i);

  if ( argc < 1)
    {
    printf("Not enough params\n");
      exit(-1);
    }


  printf("factorial of %d is %d\n", i, outcome);

}

//int main (void){
// printf("%d", fact_r(
