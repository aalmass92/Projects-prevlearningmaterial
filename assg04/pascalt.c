#include <stdio.h>
#define COUNT 17

int main(void)
{

  int rows,i,j,value,space;

  for(rows = 0; rows < COUNT; rows++){
     for(space = 0; space < COUNT-rows; space++) {
	printf("  ");
     }
    for(i = 0; i <= rows; i++){
      
      if(rows  == 0 || i == 0 )
	value = 1;
       else 
	 value = value * (rows - i + 1)/i;
	
      printf(" %4d",value);
    }
    printf("\n");
  }

 return 0;
 




}
