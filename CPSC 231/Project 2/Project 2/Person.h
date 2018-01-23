#pragma once

#include <string>

using namespace std;

class Person
{
public:
	Person();
	Person(string firstName, string lastName, int age);
	bool  valid(); // valid if names are not blank strings and age > 0
	bool get(istream &in);
	void put(ostream &out);

private:
	string firstName;
	string lastName;
	int age;

friend bool operator > (const Person &a, const Person &b);
friend bool operator < (const Person &a, const Person &b);
friend bool operator == (const Person &a, const Person &b);
};