#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int my_count = 5;

void *aWorkingThread(void *vargp){
sleep(5);
printf("From a working thread, my_count = %d\n", my_count);
return NULL;
}

void *letterThread(void *vargp){
sleep(3);
printf("From letter thread, my_count = %d\n", my_count++);
return NULL;
}

int main()
{
pthread_t tid;
pthread_t tid2;
printf("Before Thread\n");

pthread_create(&tid, NULL, aWorkingThread, NULL);
pthread_create(&tid2, NULL, letterThread, NULL);

pthread_join(tid, NULL);
pthread_join(tid2, NULL);
printf("After Thread\n");
exit(0);
}
