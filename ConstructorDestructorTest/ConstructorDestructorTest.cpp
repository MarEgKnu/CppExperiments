#include "Person.h"

#include <iostream>


void createPerson(int grades) {
    // create person on stack, once out of scope the destructor will be run and the underlying array will be deleted
    Person p = Person(grades);
}

void createPersonHeap(int grades) {
    // create person on heap, once out of the scope destructor will NOT be run, as it is a raw pointer.
    Person* p = new Person(grades);
}

int main()
{
    int grades = 5;
    std::cout << "Start of program\n";
    createPerson(grades); 
    createPersonHeap(grades);
    std::cout << "End of program\n";
}



