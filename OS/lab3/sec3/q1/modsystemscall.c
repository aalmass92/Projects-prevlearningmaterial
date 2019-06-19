#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

main()
{
    pid_t pid;
    switch(pid = fork())
    {
        case -1:
            printf("fork failed");
            break;
        case 0:  //first child
            printf("\ni'm the first child, my pid is %d", getpid());
            fflush(stdout);
            break;
        default:    //parent
            sleep(5); /** sleep for 5 seconds **/
            printf("\ni'm the parent process, my pid is %d", getpid());
            printf("\ngenerating a new child");
            fflush(stdout);
            switch(pid = fork())
            {
                case -1:
                    printf("fork failed");
                    break;
                case 0: //second child
                    printf("\nhere i am, the second child, my pid is %d", getpid());
                    break;
                default:  //parent
                    wait((int *)0);
                    printf("\nback to parent, my pid is %d", getpid());
            }
    }

    return 0;
}
