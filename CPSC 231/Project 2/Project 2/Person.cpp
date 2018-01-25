#include "stdafx.h"

#include <string>
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

//Overloaded constructor (w/ parameters)
Person::Person(string firstName, string lastName, int age)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
}

#pragma region IO

//Input from stream
bool Person::get(istream &in)
{
	in >> firstName;
	in >> lastName;
	in >> age;
	return in.good();
}

//Output to stream
void Person::put(ostream &out)
{
	if (firstName == "" || lastName == "" || age <= 0) return; //dont output if theres nothing to show

	out << left;
	out << setw(14) << lastName;
	out << setw(10) << firstName;
	out << age << endl;
}
#pragma endregion


#pragma region Operator Overloads

//Hierarchy: lastName -> firstName -> age
bool operator > (const Person &a, const Person &b)
{
	return (a.lastName > b.lastName || 
			(a.lastName == b.lastName && (a.firstName > b.firstName || 
			(a.firstName == b.firstName && a.age > b.age))));
}

//Hierarchy: lastName -> firstName -> age
bool operator < (const Person &a, const Person &b)
{
	return (a.lastName < b.lastName ||
		(a.lastName == b.lastName && (a.firstName < b.firstName ||
		(a.firstName == b.firstName && a.age < b.age))));
}

//Checks if names are equal
bool operator == (const Person &a, const Person &b)
{
	return (a.lastName == b.lastName && a.firstName == b.firstName);
}
#pragma endregion