#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include "Person.h"

using namespace std;

//Constructor
Person::Person()
{
	firstName = "";
	lastName = "";
	age = 0;
}

#pragma region IO

//Input from stream
bool Person::Get(istream &in)
{
	in >> firstName;
	in >> lastName;
	in >> age;
	return in.good();
}

//Output to stream
void Person::Put(ostream &out)
{
	if (firstName == "" || lastName == "" || age <= 0) return; //dont output if theres nothing to show

	out << left;
	out << setw(14) << lastName;
	out << setw(10) << firstName;
	out << age << endl;
}
#pragma endregion

#pragma region Operator Overloads
//sorts last -> first -> age

bool operator > (const Person &a, const Person &b)
{
	return (a.lastName > b.lastName || 
			(a.lastName == b.lastName && (a.firstName > b.firstName || 
			(a.firstName == b.firstName && a.age > b.age))));
}

bool operator < (const Person &a, const Person &b)
{
	return (a.lastName < b.lastName ||
		(a.lastName == b.lastName && (a.firstName < b.firstName ||
		(a.firstName == b.firstName && a.age < b.age))));
}

bool operator == (const Person &a, const Person &b)
{
	return (a.lastName == b.lastName && a.firstName == b.firstName && a.age == b.age);
}
#pragma endregion