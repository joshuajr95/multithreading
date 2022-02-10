/*
 * File: pthreads_prac1.c
 * Author: Joshua Jacobs-Rebhun
 * Date: February 3, 2022
 *
 *
 * This file is some beginning practice with pthreads, like creation, exit, and joining.
 */



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



const int numThreads = 10;


void *sayHello(void *args)
{
	int *threadid = (int*)args;
	printf("Hello from thread %d!\n", *threadid);
	pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
	pthread_t threads[numThreads];
	int *thread_args[numThreads];

	printf("Spawning %d threads!\n", numThreads);
	

	for(int i = 0; i < numThreads; i++)
	{
		thread_args[i] = malloc(sizeof(int));
		*thread_args[i] = i;
		pthread_create(&threads[i], NULL, sayHello, thread_args[i]);
	}


	for(int i = 0; i < numThreads; i++)
	{
		pthread_join(threads[i], NULL);
	}

	for(int i = 0; i < numThreads; i++)
	{
		free(thread_args[i]);
	}

	printf("All threads terminated!\n");

	return 0;
}
