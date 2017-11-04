// run in xterm -geometry 80x30

#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define BUFSIZE 80
char buf[BUFSIZE];
char ch;
void drawMonth(int, int , int, int);
int no_of_days(int, int);
int previous_month (struct tm *ptm);

void update_tm_dow( struct tm *ptm)
{
  time_t newtime;

  newtime = mktime (ptm);
  *ptm = *localtime (&newtime);

}

int next_month (struct tm *ptm)
{
  ptm->tm_mon++;
  if ( ptm->tm_mon >= 12 )
    {
      ptm->tm_mon = 0;
      ptm->tm_year++;
    }
  update_tm_dow (ptm);
}

// return the day number of the month
int first_day (struct tm *ptm)
{
  ptm->tm_mday = 1;
  update_tm_dow (ptm);
}

int previous_month (struct tm *ptm)
{
  ptm->tm_mon--;
  if ( ptm->tm_mon == 0 )
    {
      ptm->tm_mon = 12;
      ptm->tm_year--;
    }
  update_tm_dow (ptm);
}


int main()
{
  time_t timenow;
  struct tm *ptoday;

  struct tm today;

#if 1
  timenow = time(NULL);
#else
  time(&timenow);
#endif

  // printf ("timenow=%ld\n", timenow);
  ptoday = gmtime (&timenow);

  // I want to print YYYY-MM-DD

  // printf ("Today UTC is %4d-%02d-%02d %02d:%02d:%02d\n", ptoday->tm_year+1900, ptoday->tm_mon+1, ptoday->tm_mday, ptoday->tm_hour, ptoday->tm_min, ptoday->tm_sec);

  today = *localtime(&timenow);
  // printf ("Today loc is %4d-%02d-%02d %02d:%02d:%02d\n", today.tm_year+1900, today.tm_mon+1, today.tm_mday, today.tm_hour, today.tm_min, today.tm_sec);

  // print the month
  // strftime (buf, BUFSIZE, "%B", &today);
  //XSputs (buf);



  
  drawMonth( ptoday->tm_year+1900, ptoday->tm_mon+1, ptoday->tm_mday, ptoday->tm_wday);

   while(1){  
     if (ch == 'N' || ch == 'n'){
       next_month(ptoday);   
       first_day(ptoday);
       drawMonth( ptoday->tm_year+1900, ptoday->tm_mon+1, ptoday->tm_mday, ptoday->tm_wday);
     }
       else if (ch == 'P' || ch == 'p'){
	 previous_month(ptoday);   
      first_day(ptoday);
       drawMonth( ptoday->tm_year+1900, ptoday->tm_mon+1, ptoday->tm_mday, ptoday->tm_wday);
       }

       else if (ch == 'Q' || ch == 'q')
	 return 0;
 }
   
}


void drawdash(int row, int col, int len)
{
  int i;
  move(row,col);
  printw("+");
  for ( i=0; i<len; i++ )
    printw("-");
  printw("+");
}

void drawbar(int row, int col, int len)
{
  int i;
  for ( i=0; i<len; i++ )
    {
      move(row++,col);
      printw("|");
    }
}

int no_of_days(int year, int month){

  if (month == 1 || month ==  3 || month== 5 || month == 7 || month == 8 || month ==  10 || month == 12)
    return 31;
  else if (year %  4 == 0 && month == 2)
    return 29;
  else if (month == 2)
    return 28;
  else
    return 30;
}
void  drawMonth(int year, int  month, int curr_day, int wday){

  initscr();
  if (curr_day % 7 == 1)   
    wday = wday - 1;
  else  if (curr_day % 7 == 2)   
    wday = wday -  2;
  else  if (curr_day % 7 == 3)   
    wday = wday -  3;
  else  if (curr_day % 7 == 4)   
    wday = wday -  4;
  else  if (curr_day % 7 == 5)   
    wday = wday -  5;
  else  if (curr_day % 7 == 6)   
    wday = wday -  6;
 // else  if (curr_day % 7 == 7)   
 //  wday = wday -  0;
  


 int day = 1;

  int row = 7;
  int col = 2;
  int i = 0, j = 0;

  
  int last_day = no_of_days(year, month);
  int days_first_row;


    row = 7;
    col = (wday * 12) + 2;
    days_first_row = (7 - wday);
   
    for (j = 0; j  < (7 - wday); j++){ 
      day++;
      drawdash(row,col, 11); 
      drawdash(row + 4,col, 11);
      drawbar(row + 1,col, 3);
      drawbar(row + 1,col + 12, 3);
      move(row + 2,col + 6);
      printw("%d",( day - 1));
       col = col + 12;
} 

  int counter_loop = (last_day - days_first_row)/7;

  row = 11;
  col = 2;
  move(row,col);
  for (i = 0; i < counter_loop; i++){
    col = 2;
    
    for (j = 0; j  < 7; j++){ 
      day++;
      drawdash(row,col, 11); 
      drawdash(row + 4,col, 11);
      drawbar(row + 1,col, 3);
      drawbar(row + 1,col + 12, 3);
     
      
       move(row + 2,col + 6);
       printw("%d",( day - 1));
       move(row - 2, col - 6);
       col = col + 12;
 
    }
    row = row + 4;
    }

  row = 20 + counter_loop ;
  col = 2;
  move(row,col);
  int temp = last_day - day;
 
 for (j = 0; j  <= temp; j++){ 
    day++;
      drawdash(row,col, 11); 
      drawdash(row + 4,col, 11);
      drawbar(row + 1,col, 3);
      drawbar(row + 1,col + 12, 3);
   
       move(row + 2,col + 6);
       printw("%d",day - 1);
       col = col + 12;
   
} 

  move(2,getmaxy(stdscr));

  if (month == 1)   printw("January");
  else if (month == 2) printw("February");
else if (month == 3) printw("March");
else if (month == 4) printw("April");
else if (month == 5) printw("May");
else if (month == 6) printw("June");
else if (month == 7) printw("July");
else if (month == 8 ) printw("August");
else if (month == 9) printw("September");
else if (month == 10) printw("October");
else if (month == 11) printw("November");
else if (month == 12) printw("December");

  move(2,(getmaxy(stdscr))+ 10);
  printw("%d", year);
 move(5,2);
  printw("Monday");
  move(5,15);
  printw("Tuesday");
   move(5,26);
   printw("Wednesday");
   move(5,37);
   printw("Thursday");
   move(5,48);
   printw("Friday");
   move(5,59);
   printw("Saturday");
   move(5,70);
   printw("Sunday");
  refresh();
  ch = getch();
  clear();
  endwin();
}
