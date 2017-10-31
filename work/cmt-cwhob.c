#include <stdlib.h>                     //
#include <ncurses.h>                    //
#include <string.h>                     //
#include <unistd.h>                     //
                                        //
#define USE_CURSES                      // 
                                        // list of names, pointed character of
char *names[] = {                       // in array
  "Ahmed Almass",                       //
  "Andrew Charles",                     //
  "Bailey Taylor",                      //
  "Benjamin Goud",                      //
  "Dan Kulhanek",                       //
  "Divyadeep Parmar",                   //
  "Keith Wu",                           //
  "Mike Carlson",                       //
  "Minh Nguyen",                        //
  "Nathan Johnson",                     //
  "Nicholas Woroniuk",                  //
  "Ong Mehm",                           //
  "Seokwon Yang",                       //
  "Shane Smyck",                        //
  "Tyler Wagner",                       //
  "Vladislav Otradnov",                 //
  "Fred"                                //
};                                      //
                                        //
#define MAX_STUDENTS (sizeof(names)/sizeof(char *))// (marco), counting amount names in the pointed array
#define LINELEN 80                      // LINELEN being 80 characters
                                        //
struct student                          // allowing diff variable in a single pointer
{                                       //
  int hits;                             //
  char *name;                           //
  // char name[80];                     //
};                                      //
                                        //
struct student students[MAX_STUDENTS];  //
                                        //
int maxrow,maxcol;                      //
char line[LINELEN];                     // charater string
int idx = 0;                            //
                                        //
void init_curses ()                     // function that prints max colum and max rows
{                                       //
  initscr();                            // intial screen
  maxrow = getmaxy(stdscr);             // declaring defintion
  maxcol = getmaxx(stdscr);             // same^
  printw("maxrow = %d, maxcol = %d", maxrow, maxcol);// printing varibles for maxcolum & max row 
  move(maxrow/2, maxcol/2-strlen(line)/2);// moving curser to print
  printw(line);                         //
  refresh();                            //
}                                       //
                                        //
void exit_curses ()                     // removes cursser
{                                       //
  endwin();                             //
}                                       //
                                        //
                                        //
int main()                              //
{                                       //
  int i;                                //
  int rv;                               //
  int maxhits = 1;                      //
  int cc;                               //
  int counthits= 0;                     // declaring ^
                                        //
  for ( i=0 ; i<MAX_STUDENTS ; i++ )    //  for loop that loop until the max_students available
    {                                   //
      students[i].hits = 0;             //
      students[i].name = names[i];      //
    }                                   //
                                        //
                                        //
  strcpy(line,"Hello World.");          // print from string
#ifdef USE_CURSES                       // excute if this is true
  init_curses ();                       //
  curs_set(0);                          //
  // nocbreak ();                       //
  // nodelay (stdscr,TRUE);             //
#endif                                  // excute if this is true
  //  for ( idx=0 ; idx<MAX_STUDENTS ; idx++ )//
  int totalhits = 0;                    //
  while (1)                             //
    {                                   //
      int i;                            //
      if ( totalhits >= MAX_STUDENTS )  // looping until number of clicks over the max students in the pointed string
	{                                      //
	  for ( i=0 ; i<MAX_STUDENTS ; i++ )   //  incrementing the amount of total hits
	    students[i].hits = 0;              //
	  totalhits = 0;                       //
	}                                      //
      idx++;                            // incrementing the index
      idx = idx % MAX_STUDENTS;         //idx cant be more than the max strudents
      if ( students[idx].hits > 0 )     //
	continue;                              //
                                        //
      strcpy (line,students[idx].name); // printing name from pointed string
#ifdef USE_CURSES                       // excute if this is true
      erase ();                         //
      move(maxrow/2, maxcol/2-strlen(line)/2);// moving curser
      printw(line);                     // print from string
      move (0,0);                       // moving curser
      refresh ();                       //
      timeout (50);                     //  sec timing
      cc = getch();                     // excute after entering
#else                                   //
      usleep (100000);                  //
      printf ("%s\n", line);            // print string
      cc = getchar();                   //excute
#endif                                  //
      if ( tolower(cc) == 'q' )         // excutes when pressing q
	break;                                 //
      if ( cc == ' ' )                  //
	{                                      //
	  students[idx].hits++;                //
	  totalhits++;                         //
#ifdef USE_CURSES                       //
	  timeout (-1);                        //
	  getch();                             //
#else                                   //
	  getchar();                           //
#endif                                  //
	}                                      //
    }                                   //
                                        //
                                        //
                                        //excute 
#ifdef USE_CURSES                       //
  getch ();                             //
  exit_curses ();                       //
#endif                                  //
}                                       //
