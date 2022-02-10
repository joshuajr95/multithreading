/*
 * File: pthreads_return.c
 * Author: Joshua Jacobs-Rebhun
 * Date: February 5, 2022
 *
 * 
 * This file practices returning values from spawned threads.
 */



 #include <stdio.h>
 #include <stdlib.h>
 #include <pthread.h>



const int numThreads = 10;
int *retVals[numThreads];



void *addTen(void *args)
{
	int *threadid = (int*)args;
	
	int *sum = (int*)malloc(sizeof(int));

	*sum = *threadid + 10;

	pthread_exit((void*)sum);
}




int main(int argc, char *argv[])
{
	pthread_t threads[numThreads];
	
	int *threadIDs[numThreads];

	for(int i = 0; i < numThreads; i++)
	{
		threadIDs[i] = (int*)malloc(sizeof(int));
		*(threadIDs[i]) = i;
		pthread_create(&threads[i], NULL, addTen, threadIDs[i]);
	}

	for(int i = 0; i < numThreads; i++)
	{
		retVals[i] = (int*)malloc(sizeof(int));
		pthread_join(threads[i], (void**)&retVals[i]);
		printf("Thread %d returned value %d\n", *threadIDs[i], *retVals[i]);

		free(retVals[i]);
		free(threadIDs[i]);
	}

	

	return 0;
}

