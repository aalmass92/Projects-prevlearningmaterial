#include <stdio.h>
#define COUNT 16

int main(void)
{

  int rows,i,j,value;

  for(rows = 0; rows <= COUNT; rows++){
    
    for(i = 0; i <= rows; i++){
      
      if(rows  == 0 || i == 0 )
	value = 1;
       else 
	 value = value * (rows - i + 1)/i;
	
      printf("%5d ",value);
    }
    printf("\n");
  }

 return 0;
 




}
