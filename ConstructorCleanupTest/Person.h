#pragma once
#include <iostream>
class Person
{
public:
	int* grades;
	Person* friends;
	// consttructor
	Person(int amountOfGrades, int amountOfFriends);
	Person(int amountOfGrades, int amountOfFriends, bool padding);
	Person();

};
