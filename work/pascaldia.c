#include <stdio.h>                // library where files to use basic functions 
                                               // 
#define COUNT 20 // defines a constant variable where COUNT is always 20 and 
   
int pascal[COUNT][COUNT];  // pascal defined as 2D integer array where COUNT is 
 // the values stored   
             
/* this function will set the numbers so it doesnt ever get lower than 1
where num is the variable and the function name is numlen
 */ 
int numlen (int num)                           // function protoype 
{                                              // 
  int size = 0;                       //  delcaring that size is equal to  0
  while ( num > 0 )                     // varible num is greater than 0 
    {                                          // 
      num /=10;                                // num = num / 10
      size++;                                  //  size adds by 1
    }                                          // 
  return size;                                 //  
}                                              // 
/* this function gives the character limit 
*/ 
int get_linelen(int row)                       //  function prototype 
{                                              // 
  int i;                                       // 
  int charcount = 0;                           // 
  for ( i=0 ; i<=row ; i++ )                   //  
    charcount += numlen(pascal[row][i]) + 1;   // 
  return charcount;                            // 
}                                              // 
/* this function calculates the ammount of rows needed
 */ 
void generate_data()                           // 
{                                              // 
  int row,j;                                   // 
  for ( row=1 ; row<=COUNT ; row++)            // 
    {                                          // 
      if ( row == 1 )                          // 
        {                                      // 
          pascal[row][0] = 1;                  // 
          continue;                            // 
        }                                      // 
      pascal[row][0] = 1;                      // 
      for ( j=1 ; j<row ; j++ )                // 
        {                                      // 
          pascal[row][j] = pascal[row-1][j-1]  // 
            + pascal[row-1][j];                // 
        }                                      // 
    }                                          // 
}                                              // 

/* this function prints out the value correctly and keeps the 80 character limit in line as well correct spacing after value


 */ 
void print_one_row(int row, int maxlinelen)    // function protype with 2 variables 
{                                              // 
  int i;                                       // i  loop control varible 
  int curlen = get_linelen(row);               //  
  int needspaces = maxlinelen/2 - curlen/2;    // 
  while (needspaces-->0)                       // 
    putchar(' ');                              // 
  for ( i=0 ; i<row ; i++ )                    // 
    printf ("%d ", pascal[row][i]);            // 
  printf("\n");                                // 
}                                              // 
                                               // 
int                                            // 
main(void)                                     // 
{                                              // 
  int row,i,j;                                 // 
  int maxlinelen;                              // 
  generate_data();                             // 
                                               // 
  /* prints the pascal trangle up words
   */  
  maxlinelen=get_linelen(COUNT-1);             // 
  for ( row=1 ; row<COUNT ; row++ )            // 
    print_one_row(row, maxlinelen);            // 
 
 /* prints pascal trangle it down words
   */ 
  for ( row=COUNT-2 ; row>=1 ; row-- )         // 
    print_one_row(row, maxlinelen);            // 
                                               // 
                                               // 
}                                              // 
