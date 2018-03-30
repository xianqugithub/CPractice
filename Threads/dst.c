#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *aWorkingThread(void *vargp){
sleep(5);
for (int i=0; i<10; i++){
printf("%d\n", i);
sleep(2);
}
return NULL;
}

void *letterThread(void *vargp){
sleep(3);
for (int i=0; i<10; i++){
printf("%c\n", i+65);
sleep(4);
}
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
