#include <stdio.h>
#define ROWS 15 
#define TRUNK_HEIGHT 10
#define TRNK_WIDTH 4

int main(void)

{
  int row,star,space,H;
  printf ("$ startree\n");
  //rows
    for (row = 1; row <= ROWS; row++){
      //print space
      for(space = 1; space <= ROWS-row; space++) {
	printf(" ");
      }
      //print star
 
   for (star = 0; star != 2*row - 1; star++) {
      printf("*");
   }
  printf("\n");
    }
 
    int i,j,k = 1;

  for ( i = 1; i < TRUNK_HEIGHT; i++ ){
    k = 1;
      while (k <= ROWS - 3){
      printf(" ");
      k++;
      }

    j = 1;
    while (j <= (TRNK_WIDTH + 1)){ 
	printf("H");
	j++;
    }
     
      printf("\n");
}

    return 0;
}


  //    }// height
  //for (row = 1; row <= TRUNK_HEIGHT; row++){
      //print space
  //  for(space =1; space <= ROWS-row; space++) {
  //	printf("  ");
  //}
      //print H
    //  if ( H=5)
    // else if ( TRNK_WIDTH % 2 == 0)
    //	TRNK_WIDTH++;
    //{
   //     printf("H");
    // }
    // printf("\n");
    
