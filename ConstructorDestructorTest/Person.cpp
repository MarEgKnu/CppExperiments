#include "Person.h"


// consttructor
Person::Person(int _grades[]) {
	grades = _grades;
	std::cout << "Ran constructor\n";
}
// destructor
Person::~Person() {
	delete[] grades;
	std::cout << "Ran destructor\n";
}


