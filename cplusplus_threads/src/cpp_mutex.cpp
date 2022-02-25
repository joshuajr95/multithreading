#include <iostream>
#include <thread>


const int numThreads = 10;

int counter = 0;
std::mutex counter_lock;

void inc_dec()
{
    counter_lock.lock();
    counter++;
    counter--;
    std::cout << "Counter is: " << counter << std::endl;
    counter_lock.unlock();
}


int main(int argc, char *argv[])
{
    std::thread threads[numThreads];

    for(int i = 0; i < numThreads; i++)
    {
        threads[i] = std::thread(inc_dec);
    }

    for(int i = 0; i < numThreads; i++)
    {
        threads[i].join();
    }

    return 0;
}