#pragma once

#include <string>

using namespace std;

class Person
{
public:
	Person();
	bool Get(istream &in);
	void Put(ostream &out);
private:
	string firstName;
	string lastName;
	int age;

friend bool operator > (const Person &a, const Person &b);
friend bool operator < (const Person &a, const Person &b);
friend bool operator == (const Person &a, const Person &b);
};