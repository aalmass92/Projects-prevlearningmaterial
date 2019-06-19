#include <stdio.h>

int main ()
{

  int x; /* x is a local varaible being a interger of main function  */  

  int *p; /* a pointer to a variable type which is an integer address */

  x = 2; 

  printf("variable %d\n",x);
  p = &x;  /* stores address of x in pointer variable */ 

  printf("P contains the memory address of variable x (pointer) p= %p\n", p);
  *p = 5; /* change the value (of variable x) at the memory block pointed to by\
  the pointer p */
  printf("variable x = %d\n",x);
  printf(" variable (pointer) p = %p\n",p);

  printf("%p\n",p);
  printf("%d\n",*p);
}

  
