#include "Person.h"

#include <iostream>


void createPerson(int grades) {
    // create person, once out of scope the destructor will be run and the underlying array will be deleted
    Person p = Person(grades);
}

int main()
{
    int grades = 5;
    std::cout << "Start of program\n";
    createPerson(grades); 
    std::cout << "End of program\n";
}



