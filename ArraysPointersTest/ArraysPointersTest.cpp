
#include <iostream>

void printarray(int intArr[], int size) {
    // no guarrenteed size-checking of raw arrays, so size must be included!
    // sizeof() does not return an accurate array size, it returns the POINTER SIZE (8 byte memory addr), as the array parameter is implicitly casted to a pointer to the array, not passed by value
    // So instead the argument is actually "int* intArr" instead.
    std::cout << "Computed byte size of array: " << sizeof(intArr) << "\n";
    for (int i = 0;i < size;i++) {
        std::cout << intArr[i] << "\n";
    }
}

int main()
{
    srand(time(NULL));
    // init array of 5 elements on the stack. It must be a constant value at compile time. eg. int intArr[rand()]; would fail to compile
    int intArr[5] = { 1,2,3,4,5 };
    // sizeof() works here because the intArr is not a pointer, but is the actual value.
    std::cout << "Real byte size of array: " << sizeof(intArr) << "\n";
    printarray(intArr, 5);

    // create a new array of rand() elements on the free store. This can be a runtime variable, and does not need to be a constant.
    int size = rand();
    int* heapArr = new int[size];
    std::cout << "Real byte size of heap array: " << size << "\n";
    // we still can't fetch the size of the array from the array itself. Sizeof will return 8 bytes as it returns the size of the pointer. Thus, we must pass the size aswell
    printarray(heapArr, size);
}
