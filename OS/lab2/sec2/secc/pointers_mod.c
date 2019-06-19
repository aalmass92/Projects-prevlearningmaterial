#include <stdio.h>

int main ()
{

  int x, y; /* x is a local varaible being a interger of main function  */  

  int *p; /* a pointer to a variable type which is an integer address */
  int *s;
  x = 2; 

  printf("variable %d\n",x);
  p = &x;  /* stores address of x in pointer variable */ 
  s = &y;

  
  printf("P contains the memory address of variable x (pointer) p= %p\n", p);
  *p = 5; /* change the value (of variable x) at the memory block pointed to by  the pointer p */
  printf("variable x = %d\n",x);
  printf(" variable (pointer) p = %p\n",p);
  printf(" variable (pointer) s = %p\n",s);

  y = 10;
 printf("variable y = %d\n",y);
 
 *s = *s + 5;

  printf("variable y = %d\n",y);

}

  
