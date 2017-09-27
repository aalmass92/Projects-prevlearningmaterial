#include <stdio.h>
#define ROWS 10
int main (void)
{
  int i,a;
  printf ("$ patstar\n");
  for (i = 1; i <= ROWS; i++){
    for (a = 1; a <= i; a++) {
      printf("*");
  }
  printf("\n");
}

}
