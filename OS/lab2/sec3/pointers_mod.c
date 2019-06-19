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

  
  printf("p contains the memory address of variable x (pointer) p= %p\n", p);
  printf("s contains the memory address of variable y (pointer) s= %p\n", s);
 
  *p = 5; /* assign 5 value to a pointer variable*/
  printf("variable x = %d\n",x);
  printf(" variable (pointer) p = %p\n",&p);
  printf(" variable (pointer) s = %p\n",&s);

  y = 10;
 printf("variable y = %d\n",y);
 
 *s = *s + 5;

  printf("variable y = %d\n",y);

}

  
