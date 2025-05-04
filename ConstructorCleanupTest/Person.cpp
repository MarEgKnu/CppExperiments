#include "Person.h"
#include <stdexcept>

// memory leak constructor. Will not clean up "grades" if an exception is thrown after
Person::Person(int amountOfGrades, int amountOfFriends) {
	if (amountOfGrades < 0) {
		throw std::invalid_argument("negative grade count");
	}
	// allocate new int array on the heap
	grades = new int[amountOfGrades];
	// if this IF statement returns true and throws an exception, the above "grades" pointer will not be cleaned up!
	if (amountOfFriends < 0) {
		throw std::invalid_argument("negative friend count");
	}
	// allocate new person array on the heap
	friends = new Person[amountOfFriends];
	std::cout << "Ran constructor\n";
}


// memory safe constructor. Will clean up if it fails
Person::Person(int amountOfGrades, int amountOfFriends, bool padding) {
	try {
		if (amountOfGrades < 0) {
			throw std::invalid_argument("negative grade count");
		}
		// allocate new int array on the heap
		grades = new int[amountOfGrades];
		// if this IF statement returns true and throws an exception, the above "grades" pointer will not be cleaned up!
		if (amountOfFriends < 0) {
			throw std::invalid_argument("negative friend count");
		}
		// allocate new person array on the heap
		friends = new Person[amountOfFriends];
	}
	catch (std::exception e) {
		// if it catches any exception, clean up the potentially acquired memory and rethrow
		if (grades) delete[] grades;
		if (friends) delete[] friends;
		throw e;
	}
	
	std::cout << "Ran constructor\n";
}




// basic constructor
Person::Person() {
	grades = nullptr;
	friends = nullptr;
}


