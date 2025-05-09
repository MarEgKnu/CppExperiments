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




void sharedPtrTest(std::shared_ptr<Person> sharedPersonPtr2) {
	// print use the use count for the shared pointer after func all. Should be 2 as the func argument was copied.
	std::cout << "shared_ptr use count after function call: " << sharedPersonPtr2.use_count() << "\n";

	// since both shared pointers point to the same item, changing one means changing the other, even though they are two seperate objects
	sharedPersonPtr2->Name = "Marius K";


	// once it exists this function, the shared_ptr passed as argument will be deleted, and the use count decremented by 1.
}


void weakPtrTest() {
	// set seed for srand to get a random number
	srand(time(0));
	// create new shared ptr
	std::shared_ptr<Person> sharedPersonPtr = std::shared_ptr<Person>(new Person("Julius", 22));
	// there is a 50% chance that the sharedPtr will be reset, ie deleted.
	int randomInt = rand();
	if ((randomInt % 2) == 0) {
		sharedPersonPtr.reset();
	}
	// create weak ptr from the shared ptr.
	std::weak_ptr<Person> weakPersonPtr = std::weak_ptr<Person>(sharedPersonPtr);
	// if the shared ptr was deleted before, then the if statement fails. If the weak ptr is still valid, then it proceeds and returns a new shared ptr "p".
	// this means the underlying object will not be deleted even if the last shared_ptr is deleted after lock() is called, as the new shared ptr will increment the use_count by 1.
	// when the new shared_ptr goes out of the if statement, it is also deleted.
	if (std::shared_ptr<Person> p = weakPersonPtr.lock()) {
		std::cout << "Locking weak pointer and  returning shared ptr!\n";
		
	}
	else {
		std::cout << "Weak ptr was invalid!\n";
	}
	
}



int main()
{
	// create new shared pointer, pointing to a Person object on the free store with a default deleter
	std::shared_ptr<Person> sharedPersonPtr = std::shared_ptr<Person>(new Person("Marius", 25));
	// print use the use count for the shared pointer, should be 1
	std::cout << "shared_ptr use count: " << sharedPersonPtr.use_count() << "\n";
	sharedPtrTest(sharedPersonPtr);

	weakPtrTest();
}

