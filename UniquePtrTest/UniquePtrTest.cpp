#include "Person.h"
#include <iostream>

void printPersonDataPtrRef(const std::unique_ptr<Person>& personptr) {
	std::cout << "Age:" << personptr->Age << "\n";
	std::cout << "Name:" << personptr->Name << "\n";
}

void printPersonDataRef(const Person& person) {
	std::cout << "Age:" << person.Age << "\n";
	std::cout << "Name:" << person.Name << "\n";
}




void uniquePtrTest() {
	// create unique ptr to new instance of Person allocated on free store, using the default deleter
	std::unique_ptr<Person> uniquePersonPtr = std::unique_ptr<Person>(new Person("Marius", 25));
	//using make_unique
	uniquePersonPtr = std::make_unique<Person>("John", 30);
	// only allowed to move the unique_ptr like so, not allowed to copy it
	std::unique_ptr<Person> uniquePersonPtr2 = std::unique_ptr<Person>(move(uniquePersonPtr));
	uniquePersonPtr2->Name = "Marius K";
	std::cout << uniquePersonPtr2->Name + "\n";

	// you can however make a reference to the uniqueptr, and have both exist at the same time.
	std::unique_ptr<Person>& uniquePersonPtrRef{ uniquePersonPtr2 };

	std::cout << uniquePersonPtr2->Name + "\n";
	std::cout << uniquePersonPtrRef->Name + "\n";
	

	// two diffrent ways to pass uniqueptr's around while retaining ownership
	// first, a const reference to the unique_ptr itself.
	printPersonDataPtrRef(uniquePersonPtrRef);
	
	//second, a const reference to the underlying object which it is pointing to
	printPersonDataRef(*uniquePersonPtr2.get());

	// once it exists this function, the unique_ptr will automatically be deleted, and its destructor ran.
}



int main()
{
	uniquePtrTest();
}

