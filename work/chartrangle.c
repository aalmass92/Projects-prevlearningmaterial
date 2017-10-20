#include <stdio.h>

#define WIDTH  80


//char arr[HEIGHT][WIDTH];

int main(int argc, char* argv[])
{

 int x,y, HEIGHT;
 int  up = 0;   //

if (argc == 2)
  HEIGHT = atoi(argv[1]);
 else
   HEIGHT = 25;

char arr[HEIGHT][WIDTH];

  for ( y=0 ; y<HEIGHT ; y++ )
      for ( x=0 ; x<WIDTH ; x++ )
	arr[y][x] =' ';


  for ( x=0 ; x<WIDTH ; x++ )
    arr[HEIGHT/2][x] = '-';
	
	int col;
	int row = HEIGHT/2;

	for (col = 0; col <= HEIGHT/2; col++){
		arr[row][col] ='*';
		row--;
}

	row = 1;
	
	
	
	for (col = (HEIGHT/2 + 1); col< WIDTH; col++)	{
	
		
		if (up == 0){
		arr[row][col] ='*';
		row++;
		}
		else {		
		arr[row][col] ='*';
		row--;	
		}
		
		if (row == (HEIGHT - 1))
			up = 1;
		else if (row == 0)
			up = 0;
			
	}
	

  for ( y=0 ; y<HEIGHT ; y++ )
    {
      for ( x=0 ; x<WIDTH ; x++ )
	putchar (arr[y][x]);
      putchar ('\n');
    }
}
