#include <stdio.h>

int funtop( int a, int b, char *str);
int funbot( int  a ,int  b , char *str);

int funtop( int a, int b, char *str){

  printf("Address of funtop is: 0x%0x\n", &funtop);
  printf("funtop1 a%d b%d\n", a,b);
  a = a * 2;
  b = b * 3;
  
  printf("funtop2 a%d b%d\n", a,b);

  int return_value = funbot(a,b,str);

  printf("return is %d\n", return_value);
  return return_value;
}


int funbot(int a ,int  b , char *str){
  printf("funbot a%d b%d\n", a,b);
  printf("Address of funbot is: 0x%0x\n", &funbot);

  printf("%s\n", str);

  register int sp asm ("sp");
  printf("stack pointer is at 0x%x\n",sp);
  //print front stack here
  return a + b;	 
}


int main (int argc, char **argv[]){

  int a = 5;
  int b = 6;
  char str_m[] = "hello\0";
  funtop(a,b,str_m);

  return 0;
}
