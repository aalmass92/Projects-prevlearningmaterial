#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

struct arg_set {
  char inputArray[80];
  int count;
};

void * getChar(void *args) {
  struct arg_set *val = args;
  char c;
  int numelements = 0;
  printf("Enter Characters\n");
  int nc = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || numelements >= 79) {
      break;
    }
    val->inputArray[numelements] = c;
    numelements++;
  }
  val->inputArray[numelements] = '\0';
}

void * printAscii(void *args) {
  struct arg_set *val = args;
  char c;
  int index = 0;
  while ((c = val->inputArray[index]) != '\0') {
    printf("The ascii value of %c is %d\n", c,c);
    index++;
  }
}

void *count(void *args) {
  struct arg_set *val = args;
  char c;
  int index = 0;
  while ((c = val->inputArray[index]) != '\0') {
    index++;
  }
  val->count = index;
}

int main() {
  pid_t pid;
  pid = fork();
  struct arg_set output;
  if (pid == 0)  {
    /* child process will create threads */
    pthread_t td1, td2;
    pthread_create(&td1, NULL, getChar, (void*) &output);
    pthread_join(td1, NULL);
    pthread_create(&td1, NULL, printAscii, (void*) &output);
    pthread_create(&td2, NULL,count , (void*) &output);
    pthread_join(td1,  NULL);
    pthread_join(td2,  NULL);
    printf ("Number of characters are %d\n", output.count);
  } else {
    /* Parent has to wait for child to finish */
    wait();
  }
  return 0;
}
