#pragma once
#include <iostream>
class Person
{
public:
	std::string Name;
	int Age;

	// consttructor
	Person(std::string&& name, int age);
	// destructor
	~Person();

};



