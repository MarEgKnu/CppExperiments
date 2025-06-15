
#include <iostream>
#include "person.h"


void raw_ptr_allocation() {
    Person* person = new Person(10);


    delete person;
}

void unique_ptr_allocation() {
    std::unique_ptr<Person> person = std::make_unique<Person>(10);



}

int main()
{
    raw_ptr_allocation();
    std::cout << "Decallocated raw pointer";
    unique_ptr_allocation();
    std::cout << "Automatically decallocated unique_ptr";
}

