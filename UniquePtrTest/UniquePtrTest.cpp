#include "Person.h"
#include <iostream>

void uniquePtrTest() {
	std::unique_ptr<Person> uniqueIntPtr = std::unique_ptr<int>(new int(5));
	// only allowed to move the unique_ptr like so, not allowed to copy it
	std::unique_ptr<int> uniqueIntPtr2 = std::unique_ptr<int>(move(uniqueIntPtr));
}

int main()
{
	uniquePtrTest();
}

