#pragma once

#include <iostream>
class Person
{
public:
	int* grades;

	// consttructor
	Person(int _grades) {
		grades = new int[_grades];
		std::cout << "Ran constructor\n";
	}
	// destructor
	~Person() {
		delete[] grades;
		std::cout << "Ran destructor\n";
	}

};


