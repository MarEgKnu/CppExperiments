#include "Person.h"
// consttructor
Person::Person(std::string&& name, int age) {
	Name = name;
	Age = age;
	std::cout << "Ran constructor\n";
}
// destructor
Person::~Person() {
	std::cout << "Ran destructor\n";
}
