/* The Client. Share memory segments synchronyzed with semaphores. */
/* This program uses shared memory with key 99 and semaphore set with key 9900 */
#include <stdio.h>
#include <sys/shm.h>
#include <time.h>
#include <sys/sem.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>

#define TIME_MEM_KEY  99
#define TIME_SEM_KEY  9900
#define SEG_SIZE ((size_t)100) /*size of segment */
#define oops(m,x) {perror(m); exit(x); }
union semun {int val; struct semid_ds *bf; ushort *array; };

main()
{
	int seg_id, semset_id;
	char *mem_ptr, *ctime();
	long now;
	
/* create a share memory segment */
seg_id = shmget( TIME_MEM_KEY, SEG_SIZE, IPC_CREAT|0777 );
if ( seg_id == -1 )
 oops("shmget",1);
/* attach to the segment and get a pointer pointer */
mem_ptr = shmat( seg_id, NULL, 0 );
if ( mem_ptr == (void *)- 1 )
 oops("shmat",2);
/* connect to semaphore set 9900 with 2 semaphores */
semset_id = semget( TIME_SEM_KEY, 2, 0 );
wait_and_lock( semset_id );
printf("The time, direct from memory:... %s", mem_ptr);
release_lock( semset_id );
shmdt( mem_ptr ); /* dettach */
}

/* build and execute a 2 - element action set: wait for 0 on n_writers and increment n_readers*/
wait_and_lock(int semset_id)
{
	union semun sem_info;
	struct sembuf actions[2]; /*action set */
	actions[0].sem_num = 1; /* sem[1] is n_writers */
	actions[0].sem_flg = SEM_UNDO; /*auto clean */
	actions[0].sem_op = 0; /*wait for 0 */
	actions[1].sem_num = 0; /* sem[0] is n_readers */
	actions[1].sem_flg = SEM_UNDO; /*autoclean */
	actions[1].sem_op = +1; /* increment num_readers */
	if (semop( semset_id, actions, 2) == -1)
		oops("semop:locking", 10);
}
/* build and execute a 1-element action set. Decrement num_readers */
release_lock( int semset_id )
{
	union semun sem_info; 
	struct sembuf actions[1]; /*action set */
	actions[0].sem_num = 0; /*sem[1] is n_writers */
	actions[0].sem_flg = SEM_UNDO; /*auto clean */
	actions[0].sem_op = -1; /*decrement writer count */
	if ( semop( semset_id, actions, 1) == -1)
		oops("semop:unlocking",10);
}

