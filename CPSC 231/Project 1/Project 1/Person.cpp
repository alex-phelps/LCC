#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{
	firstName = "";
	lastName = "";
	age = 0;
}

bool Person::Get(istream &in)
{
	in >> firstName;
	in >> lastName;
	in >> age;
	return in.good;
}

void Person::Put(ostream &out)
{
	out << firstName << "\t" << lastName << "\t" << age;
}

bool operator > (const Person &a, const Person &b)
{
	return (a.lastName > b.lastName || b.firstName > b.firstName || a.age > b.age);
}

bool operator < (const Person &a, const Person &b)
{
	return (a.lastName < b.lastName || b.firstName < b.firstName || a.age < b.age);
}

bool operator == (const Person &a, const Person &b)
{
	return (a.lastName == b.lastName && b.firstName == b.firstName && a.age == b.age);
}