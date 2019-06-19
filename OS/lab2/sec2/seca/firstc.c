#include <stdio.h>  /*library header which include functions. example: printf*/
#include <stdlib.h> /* same as above but different functions */
#define MAX 10 /* user defined-function max being the macro 10 being the replacement */


int fib(int n);

int i=12345; /* int data type,  i being the global variable outside of main 1234 is the constant   */
double y=1.23456;



void display_varaibles() /* user-function when called prints the local y and global variable y */ 
{

  double y= 4.352;
  printf("i=%d, y=%f\n", i,y);
}

  int main () /*  integer main function is to executes task during runtime */
 {

   printf("i=%d, y=%f\n", i,y); /* prints variables i& y */
   display_varaibles(); /* calling function */
   int c, i=0; /* c & i = local variable and replacing global i to local 0 */ 


   for (c = 0; c<= MAX; c++) /* for loop starting c as 0 finshing loop when equal-less value MAXX and incriment c by 1 */
     {
       printf("%d\n",fib(i)); 
       i++;
     }
       return 0;
       
 }


 

   int fib(int n) /* user defined with integer n being the parameter if the value  of n = 0 it returns 0 if n = 1 returns 1 and other than that it does an mathical operation  */
   {
      
     if ( n == 0 ) 
       return 0;
     else if ( n == 1 )
       return 1;
     else
       return ( fib(n-1) + fib(n-2) );
   }
