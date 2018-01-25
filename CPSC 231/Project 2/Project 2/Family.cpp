#include "stdafx.h"

#include <iostream>
#include <stdexcept>
#include "Family.h"

Family::Family()
{
	//init  to 0
	len = 0;
}

Family::~Family()
{
	for (int i = 0; i < len; i++)
		delete map[i];
}

//Returns count of valid people
int Family::length()
{
	return len;
}

//Adds Person to array if there is room
bool Family::insert(Person person)
{
	map[len] = new Person;

	if (map[len] == NULL) return false;

	*(map[len]) = person;

	len++;
	return true;
}

//Removes a Person
bool Family::remove(string firstName, string lastName)
{
	int n = find(firstName, lastName);

	if (n < 0 || n >= len)
		return false;

	//delete person we are removing
	delete map[n];

	//move pointers one space back
	for (int i = n; i < len - 1; i++)
	{
		map[i] = map[i + 1];
	}

	len--;

	return true;
}

//Prints to output stream
void Family::display(ostream &out)
{
	out << "Last          First     Age" << endl;
	out << "------------  --------  ---" << endl;
	for (int i = 0; i < len; i++)
		map[i]->put(out);
}

//Sorts map
void Family::sort()
{
	//Bubble sort
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len - 1; j++)
			if (*(map[j]) > *(map[j + 1]))
				swap(map[j], map[j + 1]);
}

//Finds person with given names in map and returns the index
int Family::find(string firstName, string lastName)
{
	for (int i = 0; i < len; i++)
		if (map[i]->firstName == firstName && map[i]->lastName == lastName)
			return i;

	return -1;
}