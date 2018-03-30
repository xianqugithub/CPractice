#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *aWorkingThread(void *vargp){
 for (int i=0; i<100; i++){
 printf("%d\n", i);
 }
 return NULL;
 }

int main(){
 pthread_t tid;

 printf("Before Thread\n");
 pthread_create(&tid, NULL, aWorkingThread, NULL);
 printf("Main Program\n"); /* These two lines randomly insert in between the cycles */
 printf("Main Program2\n"); /**/ 
 pthread_join(tid, NULL);
 printf("After Thread\n");
 exit(0);
 }
