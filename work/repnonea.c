#include <stdio.h>
#include <string.h>

int top = -1;

float myStack[100];//100 values in array
float x,y, result;

// creating the stack (pushing the value in the stack)
void push(float num){
  top++; // increases the index
  myStack[top] = num; // seting up the value to index in the array
}
// the value that you are poping
float pop(){
  float myNum;
  myNum = myStack[top]; 
top--; // when removing pop decreases the index
  return myNum;
}
// displays all the stack values
void myDisplay(int argCount){

  int i;

  if (argCount == 1)
    printf("%.1f ", myStack[top]); 
  else { 
    printf("[");
    for(i = 0; i <= top; i++ )
      printf(" %.0f", myStack[i]);
  }

}

int main(int argc, char* argv[]){
  char temp1[100] = ""; //array of characters

  if (argc == 1){

// this excutes the program
    while ((strcmp(temp1, "q") != 0)){
      gets(temp1);    // get string
// leave the program

      if ((strcmp(temp1,"q")== 0))
	  return 0;
// puting operators
      else if ((strcmp(temp1,"+")== 0)){
      x  = pop();
      y =  pop();
      result = y + x;
      push(result);
      myDisplay(argc);
      }

      else if ((strcmp(temp1,"-")== 0)){
      x  = pop();
      y = pop();
      result = y  - x;
      push(result);
      myDisplay( argc);
      }

      else if ((strcmp(temp1,"/")== 0)){
      
      x  = pop();
      y = pop();
      result = y / x;
      
      push(result);
      myDisplay(argc);
      }
      
      else if ((strcmp(temp1,"*")== 0)){
     
      x  = pop();
      y = pop();
      result  = y * x;
      push(result);
      myDisplay(argc);
      }
     
      else {
       push(atoi(temp1));    // atoi converts string into integer
       myDisplay(argc);
      } 
    }
}

  else if ((strcmp(argv[1], "-v")) == 0 ){
    printf("[]");
   
    while ((strcmp(temp1, "q") != 0)){
      gets(temp1);    // get string

      if ((strcmp(temp1,"q")== 0))
	  return 0;

      else if ((strcmp(temp1,"+")== 0)){
      x  = pop();
      y = pop();
      result = y + x;
      push(result);
      myDisplay(argc);
      }

      else if ((strcmp(temp1,"-")== 0)){
      x  = pop();
      y = pop();
      result = y  - x;
      push(result);
      myDisplay(argc);
      }

      else if ((strcmp(temp1,"/")== 0)){
      
      x  = pop();
      y = pop();
      result = y / x;
      
      push(result);
      myDisplay(argc);
      }
      
      else if ((strcmp(temp1,"*")== 0)){
     
      x  = pop();
      y = pop();
      result  = y * x;
      push(result);
      myDisplay(argc);
      }
     
      else {
       push(atoi(temp1));    // atoi converts string into integer
       myDisplay(argc);
      }
      
      printf(" ]");     
    }
   
 }
  
  return 0;
}
