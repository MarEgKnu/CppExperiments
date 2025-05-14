
#include <iostream>
#include "Person.h"

void PointerToStackTest() {
    int int1 = 23456;

    // create pointer pointing to the int1 stack variable
    int* int1ptr = &int1;

    // re-assign int1 variable to some other number
    int1 = 654321;

    // De-reference the pointer with *, and print out the result.
    std::cout << *int1ptr << "\n";
}


void PointerMathTest() {
    // create array of 10 ints on the stack
    int intArray[10]{ 1,2,3,4,5,6,7,8,9,10 };

    // create new person on stack, get a pointer to it, and use the arrow syntax to access a member
    Person p = Person(5);
    Person* personPtr = &p;
    std::cout << personPtr->grades << "\n";
    // is the same as
    std::cout << (*personPtr).grades << "\n";



    // get pointer to the first element in the array
    int* elementptr = &intArray[0];

    std::cout << "First element pointer addr: " << elementptr << "\n";
    std::cout << "First element: " << *elementptr << "\n";

    // incremenet the int which the pointer is pointing to
    (*elementptr)++;
    // increment the pointer, it now refers to the next element in the array
    elementptr++;
    std::cout << "Second element pointer addr: " << elementptr << "\n";
    std::cout << "Second element: " << *elementptr << "\n";
    // increment the pointer by 10, causing the pointer to go out of the array bounds. The result is undefined.
    elementptr = elementptr + 10;
   
    std::cout << "out of bounds pointer addr: " << elementptr << "\n";
    std::cout << "out of bounds element: " << *elementptr << "\n";

    // trying to de-reference a nullptr will usually lead to a crash.
    elementptr = nullptr;

    std::cout << "nullptr pointer addr: " << elementptr << "\n";
    //std::cout << "nullptr element: " << *elementptr << "\n"; //<-- crashes here

}


int main()
{
    PointerToStackTest();
    PointerMathTest();

    int integer = 12345;
    // get pointer from integer
    int* intPtr = &integer;
    // cast intPtr to a char pointer
    char* charPtr = (char*)intPtr;
}


