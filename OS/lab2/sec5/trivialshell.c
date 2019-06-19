// trivial shell program -- reads input, executes program

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// for waitpid
#include <sys/types.h>
#include <sys/wait.h>

#define ARGMAX 10
#define ARGLEN 100

#define MAXLINELEN 256
char cmdline[MAXLINELEN];
char scratch[MAXLINELEN];
// declare array of arguments, 
char *arglist[ARGMAX][ARGLEN];
char *argv[11];
int pid;


int main ( )
{
  int argc;
  while (1)
    {
      // come up with nice prompt
      getcwd(scratch,MAXLINELEN);
      printf("\n%s: ",scratch);
      fgets(cmdline,MAXLINELEN,stdin);
	if (strncmp(cmdline, "exit" ,strlen("exit")) == 0)
	{
	break;
	} 
      argc = sscanf(cmdline,"%s%s%s%s%s%s%s%s%s%s\n", arglist[0],arglist[1],arglist[2],arglist[3],arglist[4],arglist[5],arglist[6],arglist[7],arglist[8],arglist[9]);
      int i;
      printf("Total arguments: %d\n", argc);
      for ( i=0 ; i<argc ; i++ )
	{
	  printf("Arg %d is %s\n", i, arglist[i]);
	  argv[i] = (char *) arglist[i]; // explain this!
	}
      argv[i] = NULL;

      // execute a program using these arguments
      pid=fork();
      if ( pid<0 )
	{
	  fprintf (stderr, "Error occured on line %d, aborting shell\n", __LINE__);
	  exit(-1);
	}
      if ( pid==0 ) // the child process
	{
	  execvp ((const char *) arglist[0], argv);
	  // could find the current environment and make the system call directly
	  // execve ((const char *) arglist[0], argv, environ);
	}
      else // the parent process waits for the child to finish
	{
	  int status;
	  int rv = waitpid (pid, &status, 0);
	  if ( rv<0 )
	    {
	      fprintf (stderr, "Error occured on line %d, aborting shell\n", __LINE__);
	      exit(-1);
	    }
	}

    }

}
