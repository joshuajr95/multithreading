#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


// WILL NOT WORK ON MAC OS X SINCE THE PTHREAD_BARRIER_T TYPE IS MISSING

const int numThreads = 10;


pthread_barrier_t barrier;

void *runFunc(void *args)
{
	int *threadid = (int*)args;

	printf("Thread %d waiting at the barrier...\n", *threadid);

	pthread_barrier_wait(&barrier);

	printf("Thread %d just exited the barrier.\n", *threadid);

	pthread_exit(NULL);
}




int main(int argc, char *argv[])
{
	pthread_t threads[numThreads];


	pthread_barrier_init(&barrier, NULL, numThreads);
	
	for(int i = 0; i < numThreads; i++)
	{
		pthread_create(&threads[i], NULL, runFunc, &i);
	}


	for(int i = 0; i < numThreads; i++)
	{
		pthread_join(threads[i], NULL);
	}

	pthread_barrier_destroy(&barrier);

	return 0;
}
