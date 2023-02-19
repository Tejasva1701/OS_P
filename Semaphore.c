#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h> 
#include <semaphore.h>

sem_t sem;

void* thread_func(void* arg)
{
// Wait on the semaphore sem_wait(&sem);

printf("Thread %d: entered critical section\n", (int)arg); sleep(1);
printf("Thread %d: exiting critical section\n", (int)arg);

// Post to the semaphore sem_post(&sem);

return NULL;
}

int main()
{
sem_init(&sem, 0, 1);

pthread_t thread1, thread2;
pthread_create(&thread1, NULL, thread_func, (void*)1); pthread_create(&thread2, NULL, thread_func, (void*)2);

pthread_join(thread1, NULL); pthread_join(thread2, NULL);

sem_destroy(&sem);

return 0;
}

