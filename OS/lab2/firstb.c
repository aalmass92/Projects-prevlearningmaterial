#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int i=12345;
double y=1.23456;

void display_variables()
{

  double y= 4.352;
  printf("i=%d, y=%f\n", i,y);
}

int maint ()
{
  printf("i=%d, y=%f\n", i,y);
  display_variables();
  int c, i=0;
  for( c = 0; c <= MAX; c++)
    {
      printf("%d\n",fib(i));
      i++;
    }
  return 0;


  int fib(int n)
  {
    if (n == 0 )
      return 0;
    else if ( n == 1)
      return 1;
    else
      return (fib(n-1) + fib(n-2) );
  }
