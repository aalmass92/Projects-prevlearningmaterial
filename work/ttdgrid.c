#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define width 20
#define height 20
#define BUTTON_CORNERS 12


void grid_rows(){

}




void grid_cols(){


}

/*void draw_grid ( int rows, int cols){

  int i;
  int row = the_buttons[which].row;
  int col = the_buttons[which].col;
  char cc = the_buttons[which].cc;
  for(i = 0; i < BUTTON_CORNERS; i++)
    {
      move(row + buts[i].o_row, col + buts[i].o_col);
      addch(buts[i].ch);
    }
  move(row + 1, col + 1);
  printw(" %c ", cc);
  refresh()
}*/

int main (int argc, char* argv[]){ 

  if (argc < 2){
    printf(" Auto Maxmium ");
      }


    initscr();

    refresh();
    getch();
    endwin();



  

}
