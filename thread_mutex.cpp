#include <iostream>
#include <thread>
#include <string>
#include <mutex>


// RACE CONDITION:
// 0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
// 1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.

// MUTEX:
// 0. Mutex is used to avoid race condition.
// 1. We use lock() , unlock() on mutex to avoid race condition.

// Mutex: Mutual Exclusion

// Race condition does not occur if multiple threads are simply ACCESSING the same data; it only occurs when they are both MODIFYING the data.

//Process Analysis:

//x++ which is equal to x = x + 1;
// 3 stages from the Assembly perspective: 1) load, 2) Increment, 3) Store
// 1) Loads the value of x (any int/double etc.) into x
// 2) Add 1 to that value
// 3) Store back in x
int myBalance = 0; // intentionally made this a global variable, so it is guaranteed to be common between both threads
std::mutex Mutex_One;
void AddMoney (){
    Mutex_One.lock(); //stops the other thread from executing until the first thread to get to the CPU is done executing. must be done prior to the critical region.
    ++myBalance; // this is the race condition: critical section/region
    Mutex_One.unlock(); // Done with the critical section, so now the other thread can start it's own execution.
}

int main(){
    std::thread t1 (AddMoney);
    std::thread t2 (AddMoney);

    t1.join();
    t2.join();

    std::cout << myBalance << std::endl;
    return 0;
}