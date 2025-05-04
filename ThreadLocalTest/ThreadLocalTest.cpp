
#include <iostream>
#include <thread>
#include <vector>
#include <string>

void DoStuffSafe() {

    // the thread_local variable will not be re-declared each time the function is called on the same thread, it will keep the values.
    // The vector is a stack variable, any resources it acquires will be cleaned up when the thread is gone and its deconstructor is run.
    thread_local std::vector<int> threadVector = std::vector<int>();
    threadVector.push_back(rand());
    // print out the thread id
    std::thread::id threadId = (std::this_thread::get_id());
    std::cout << threadId;
    std::cout << "\n";

}

void DoStuffLeak(int arrIndex) {

    
    // the thread_local variable will not be re-allocated each time the function is called on the same thread, it will keep the values.
    // The array is a free store variable dynamically allocated. As it is a raw pointer the array will NOT be cleaned up when the thread is gone.
    // therefore we have a memory leak
    thread_local int* threadArray = new int[10];
    threadArray[arrIndex] = rand();
    // print out the thread id
    std::thread::id threadId = (std::this_thread::get_id());
    std::cout << threadId;
    std::cout << "\n";
}

int main()
{
    // use srand to set a starting seed for rand()
    srand(time(NULL));
    //run loop 10 times per thread, and use lambda to run the functions
    std::thread t1 = std::thread([]() {
            for (int i = 0;i < 10;i++) {
                DoStuffSafe();
                DoStuffLeak(i);
            }
        });


    std::thread t2 = std::thread([]() {
        for (int i = 0;i < 10;i++) {
            DoStuffSafe();
            DoStuffLeak(i);
        }
        });
    // wait for the threads at the end of the program
    t1.join();
    t2.join();
    std::cout << "Program end";
    
}
