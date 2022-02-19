#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


pthread_mutex_t mutex;
static int numberShouldBeZero = 0;

const int numThreads = 100;

void *runTest(void *args)
{
	// acquire mutex
	pthread_mutex_lock(&mutex);

	// critical section
	numberShouldBeZero++;
	numberShouldBeZero--;
	printf("Number: %d\n", numberShouldBeZero);
	
	// release mutex
	pthread_mutex_unlock(&mutex);

	pthread_exit(NULL);	
}


int main(int argc, char *argv[])
{
	pthread_t threads[numThreads];

	pthread_mutex_init(&mutex, NULL);

	for(int i = 0; i < numThreads; i++)
	{
		pthread_create(&threads[i], NULL, runTest, NULL);
	}

	for(int i = 0; i < numThreads; i++)
	{
		pthread_join(threads[i], NULL);
	}


	printf("Number is : %d\n", numberShouldBeZero);

	pthread_mutex_destroy(&mutex);

	return 0;
}
