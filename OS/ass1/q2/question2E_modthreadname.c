/* wordcount.c - threaded word counter for two files. */

#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

struct arg_set {
char *fname; /* two values in one arg */ /* file to examine */
  int count; /* number of words */ 
} ; 

main(int ac, char *av[]) { 
 
  pthread_t t1, t2, t3; /* two threads */

  struct arg_set args1, args2, args3; /* two argsets */
 void *count_words(void *); 

 if ( ac != 4 )
   {

   printf("usage: %s filel file2 file3\n", av[0]);
   exit(1);
 }

 args1.fname = av[1];
 args1.count = 0;
 pthread_create(&t1, NULL, count_words, (void *) &args1); 


 args2.fname = av[2];
 args2.count = 0;
 pthread_create(&t2, NULL, count_words, (void *) &args2);

 
 args3.fname = av[3];
 args3.count = 0;
 pthread_create(&t3, NULL, count_words, (void *) &args3);

 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
 pthread_join(t3, NULL);

 printf("%5d: %s\n", args1.count, av[1]);
 printf("%5d: %s\n", args2.count, av[2]);
 printf("%5d: %s\n", args3.count, av[3]);
 
 printf("%5d: total words\n", args1.count+args2.count+args3.count);
}

 void *count_words(void *a)
 {
   struct arg_set *args = a; /* cast arg back to correct type */
   FILE *fp;
   int c, prevc = '\0';
   
   if ( (fp = fopen(args->fname, "r")) != NULL ){
     while( ( c = getc(fp)) != EOF ){
       if ( !isalnum(c) && isalnum(prevc))
	 args->count++;
       prevc = c;
   }
     fclose(fp);
   }
   else
     perror(args->fname);

   return NULL;  
 }
