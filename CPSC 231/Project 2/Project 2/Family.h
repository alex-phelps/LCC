#pragma once

#include "Person.h"

#define MAX_SIZE 20

class Family
{
public:
	Family();
	~Family();
	int length();  //  Returns number of valid people in family
	bool insert(Person);  // Adds a person to the family; returns true if successful
	bool remove(string, string);  // Removes a person by last + first name; returns true if successful
	void display(ostream &out);  //  Prints family to output stream
	void sort();  //  Sorts family
	int find(string, string);  //  Finds and returns index of person by first + last name

private:
	int len;
	Person *map[MAX_SIZE];
};