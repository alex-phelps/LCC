#pragma once

#include <string>

using namespace std;

class Family;

class Person
{
public:
	Person();
	Person(string firstName, string lastName, int age);
	bool get(istream &in);
	void put(ostream &out);

private:
	string firstName;
	string lastName;
	int age;

friend Family;
friend bool operator > (const Person &a, const Person &b);
friend bool operator < (const Person &a, const Person &b);
friend bool operator == (const Person &a, const Person &b);
};