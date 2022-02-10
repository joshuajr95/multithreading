/*
 * File: pthreads_prac2.c
 * Author: Joshua Jacobs-Rebhun
 * Date: February 5, 2022
 *
 *
 * This file practices reusing pthread_t identifiers.
 */


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>




void *sayHi(void *args)
{
	int *threadid = (int*)args;
	
	printf("Hi from thread %d\n", *threadid);
	pthread_exit(NULL);
}


void *sayBye(void *args)
{
	int *threadid = (int*)args;

	printf("Bye from thread %d\n", *threadid);
	pthread_exit(NULL);
}


const int numThreads = 10;

int main(int argc, char *argv[])
{
	
	pthread_t threads[numThreads];
	
	int *threadIDs[numThreads];
	
	for(int i = 0; i < numThreads; i++)
	{
		threadIDs[i] = (int*)malloc(sizeof(int));
		*(threadIDs[i]) = i;
		pthread_create(&threads[i], NULL, sayHi, threadIDs[i]);
	}

	
	for(int i = 0; i < numThreads; i++)
	{
		pthread_join(threads[i], NULL);
	}

	
	for(int i = 0; i < numThreads; i++)
	{
		*(threadIDs[i]) = i;
		pthread_create(&threads[i], NULL, sayBye, threadIDs[i]);
	}

	for(int i = 0; i < numThreads; i++)
	{
		pthread_join(threads[i], NULL);
	}


	for(int i = 0; i < numThreads; i++)
	{
		free(threadIDs[i]);
	}
	

	return 0;
}
