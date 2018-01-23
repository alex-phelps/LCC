#pragma once

#include "Person.h"

class Family
{
public:
	Family(int);
	~Family();
	int length();  //  Returns number of valid people in family
	bool insert(Person);  // Adds a person to the family; returns true if successful
	bool remove(Person);  // Removes a person by last + first name; returns truye if successful
	void display(ostream &out);  //  Prints family to output stream
	void sort();  //  Sorts family
	int find(Person);  //  Finds and returns index of person by first + last name

private:
	int len;
	Person *map;
};