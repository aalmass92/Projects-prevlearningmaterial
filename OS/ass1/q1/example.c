#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void sig_usr(int signo){
    if(signo == SIGINT)
    printf("Signal caught!");
    return;
}

int main(void){
    pid_t pid, ppid;
    ppid = getpid();
    printf("ppid = %d\n", ppid);
    if((pid = fork()) == 0){ 
        sleep(1); // Wait for parent to finish setting up
        printf("killing parent...\n");
        kill(ppid, SIGINT);
        printf("After killing parent...\n");
    }
    else{
        printf("%d %d ",ppid, pid);
        if(signal(SIGINT,sig_usr) == SIG_ERR)
            printf("Signal processed ");
        sleep(5); // Wait to be killed
    }
    return 0;
}
