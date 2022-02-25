#include <iostream>
#include <thread>

const int numThreads = 10;


void do_stuff(int threadid)
{
	std::cout << "Hello from thread " << threadid << std::endl;
}



int main(int argc, char *argv[])
{
	std::thread threads[numThreads];

	for(int i = 0; i < numThreads; i++)
	{
		threads[i] = std::thread(do_stuff, i);
		threads[i].join();
	}

	/*
	for(int i = 0; i < numThreads; i++)
	{
		threads[i].join();
	}
	*/

	return 0;
}
