#include "Person.h"

#include <iostream>


void createPerson(int* arr) {
    // create person, once out of scope the destructor will be run and the underlying array will be deleted
    Person p = Person(arr);
}

int main()
{
    std::cout << "Start of program\n";
    int* arr = new int[5] {1,4,7,7,10}; // allocate memory on heap with "new" operator, assign to pointer
    createPerson(arr);
    std::cout << "End of program\n";
}



