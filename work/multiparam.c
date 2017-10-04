#include <stdio.h>

#define SEPARATOR printf("+----+----+----+----+----+----+\n");
#define COLUMNS 5
#define SIZE 5

int main (void)

{
  // initialize parameters
  int row, i, myArray[5] = { 1, 2, 3, 4, 5};

  // title for output
  printf(" $ multirect5\n");

  SEPARATOR
  printf("|    |  %d |  %d |  %d |  %d |  %d |\n",
  myArray[0], myArray[1], myArray[2], myArray[3],myArray[4]);
  
  SEPARATOR 

   for ( row = 1; row <= SIZE; row++){
     
    for( i = 0; i <= SIZE; i++){
      if ( i == 0){
	myArray[i] = row;
	printf("| %2.d ", myArray[i]);
      }
      else {
	myArray[i] = row * i; 
	printf("| %2.d ", myArray[i]);
      }
     
    }
    printf("|\n");
    SEPARATOR
    }

 
  
  return 0;
}
