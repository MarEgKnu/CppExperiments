#include <iostream>

//create static variable for the duration of the entire program
int staticInt = 5;


void TestLocalScope() {
    // create new automatic int array. It will run its destructor after it exists scope.
    // the array size must also be a constant, it cannot be runtime when creating a local automatic array.
    int intArr[5] = { 1,2,3,4,5 };

    // this is to show that you can use a runtime value to decide array size when you use free store allocation. 
    int* arrTwo = new int[rand()];

    // once we exit scope, arrTwo will be destructed, but not the data it points to! So we got a memory leak
}

int main()
{
    std::cout << "Start of program\n";
    
   
    // allocate memory for char array on the free store and return a pointer to it
    char* str = new char[12] {"Hello World"};
    // does NOT deallocate the underlying char array, causing a memory leak.
    str = nullptr;


    // allocate memory for new char array
    char* strTwo = new char[12] {"Hello World"};

    //deallocates the data it is pointing to.
    delete[] strTwo;


    TestLocalScope();
    std::cout << "End of program\n";
}