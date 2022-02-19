
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>



const int numThreads = 10;

sem_t semaphore;



void *runFunc(void *args)
{
	sem_wait(&semaphore);

	int *threadid = (int*)args;
	printf("Thread %d now running...\n", *threadid);

	pthread_exit(NULL);
}




int main(int argc, char *argv[])
{
	pthread_t threads[numThreads];
	sem_init(&semaphore, 0, 0);

	for(int i = 0; i < numThreads; i++)
	{
		pthread_create(&threads[i], NULL, runFunc, &i);
	}
	
	printf("Worker Threads started...\n");
	sem_post(&semaphore);

	for(int i = 0; i < numThreads; i++)
	{
		pthread_join(threads[i], NULL);
	}

	sem_destroy(&semaphore);

	return 0;
}

