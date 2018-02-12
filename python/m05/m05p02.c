#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int funtop( int a, int b, char *str);
int funbot( int  a ,int  b , char *str);

int funtop( int a, int b, char *str){

  printf("Address of funtop is: 0x%0x\n", &funtop);
  // printf("funtop1 a%d b%d\n", a,b);
  a = a * 2;
  b = b * 3;
  
  printf("funtop2 a%d b%d\n", a,b);

  int return_value = funbot(a,b,str);

  printf("return is %d\n", return_value);
  return return_value;
}


int funbot(int a ,int  b , char *str){
  char pidFile[100];
  char *line;
  size_t size = 0;
  FILE *fp = NULL;
  //  printf("funbot a%d b%d\n", a,b);
  printf("Address of funbot is: 0x%0x\n", &funbot);

  printf("%s\n", str);

  register int sp asm ("sp");
  printf("stack pointer is at 0x%x\n",sp);
  pid_t id = getpid();
  sprintf(pidFile, "/proc/%d/maps", id);
  fp = fopen(pidFile, "r");
  if (fp == NULL) {
    printf("Error reading the file");
  }
  long int top_stack = 0;
  while (getline(&line, &size, fp)!=-1) {
    if (strstr(line, "stack")) {
      printf("%s", line);
      char top[50];
      int j = 0;
      int start_storing = 0;
      for (int i=0;i<strlen(line);i++) {
        if (start_storing) {
	  if (line[i] == ' ') {
	    break;
	  }
	  top[j++] = line[i];
	}
	if (line[i] == '-') {
	  start_storing = 1;
	}
      }
      top[j] = '\0';
      top_stack = strtol(top, NULL, 16);
      printf("top of stack is 0x%x\n", top_stack);
    }
  }
  
  fclose(fp);
  return a + b;	 
}


int main (int argc, char **argv[]){

  int a = 5;
  int b = 6;
  char str_m[] = "hello";
  funtop(a,b,str_m);

  return 0;
}
