/** sigsample.c  signal sampler
 *  demonstrate how signals can kill a process,
 *  be ignored by a process, or be caught by a process
 **/
#include <stdio.h>
#include <signal.h>

void catcher() /* a function to run when a signal is caught */
{
	printf(" Ouch! \n");
	system("who");
}

main()
{
	int	i;
	printf("Type ^C during either Case 1, Case 2, or Case 3");
	printf("Case 1: no special arrangements..");
	for (i=0;i<10;i++){
		putchar('*');fflush(stdout);
		sleep(1);
	}
	putchar('\n');

	signal(SIGINT, SIG_IGN);	/* ignore INTerrupts */
	printf("Case 2: ignoring interrupts..");
	for (i=0;i<10;i++){
		putchar('*');fflush(stdout);
		sleep(1);
	}
	putchar('\n');

	signal(SIGINT, catcher);	/* handle interruptions */
	printf("Case 3: catching interrupts..");
	for (i=0;i<10;i++){
		putchar('*');fflush(stdout);
		sleep(1);
	}
	putchar('\n');
}
