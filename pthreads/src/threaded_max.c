/*
 * File: threaded_max.c
 * Author: Joshua Jacobs-Rebhun
 * Date: February 5, 2022
 *
 *
 * This file tests the efficiency of finding the maximum of an array by spawning
 * a number of threads and solving in parallel. Specifically, it tests at what size
 * of the subproblem the speedup is greatest, and how small does the subproblem have
 * to be before the thread spawning overhead begins to dominate runtime.
 */



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



const int size = 128;
int




void *getMax(void *args)
{



}


int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: ./threaded_max <numThreads>\n");
		return 1;
	}


	int numThreads = atoi(argv[1]);

	pthread_t threads[numThreads];

	for(int i = 0; i < numThreads; i++)
	{
		

	}



	return 0;
}
