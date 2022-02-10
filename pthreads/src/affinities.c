/*
 * File: affinities.c
 * Author: Joshua Jacobs-Rebhun
 * Date: February 7, 2022
 *
 * 
 * This file tests out getting and setting CPU affinities.
 */


// THIS WILL NOT WORK ON MAC OS X. UNFORTUNATELY, THIS ONLY WORKS ON LINUX AND WINDOWS.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sched.h>


int main(int argc, char *argv[])
{
	cpu_set_t cpuSet;

	int err;

	if((err = sched_getaffinity(getpid(), sizeof(cpuSet), &cpuSet)) < 0)
	{
		printf("Error: %s\n", strerror(errno));
		return 1;
	}

	printf("CPU set: %x\n", cpuSet);


	return 0;
}
