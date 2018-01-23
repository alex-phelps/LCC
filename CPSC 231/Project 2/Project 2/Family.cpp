#include "stdafx.h"

#include <iostream>
#include <stdexcept>
#include "Family.h"

Family::Family(int len)
{
	//Set array max length
	this->len = len;

	map = new Person[len];
}

Family::~Family()
{
	delete[] map;
}

//Returns count of valid people
int Family::length()
{
	int count = 0;
	for (int i = 0; i < len; i++)
		if (map[i].valid()) count++; // only count valid entries

	return count;
}

//Adds Person to array if there is room
bool Family::insert(Person person)
{
	if (len != length()) // if there is room
		for (int i = 0; i < len; i++)
			if (!map[i].valid())
			{
				map[i] = person; // replace first invalid person
				return true;
			}

	return false;
}

//Removes a Person
bool Family::remove(Person person)
{
	int i = find(person);

	if (i < 0)
		return false;

	map[i] = Person{}; // replace with blank / invalid person
	return true;
}

//Prints to output stream
void Family::display(ostream &out)
{
	out << "Last          First     Age" << endl;
	out << "------------  --------  ---" << endl;
	for (int i = 0; i < len; i++)
		if (map[i].valid())
			map[i].put(out);
}

//Sorts map
void Family::sort()
{
	//Bubble sort
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len - 1; j++)
			if (map[j] > map[j + 1])
				swap(map[j], map[j + 1]);
}

//Finds person with given names in map and returns the index
int Family::find(Person person)
{
	for (int i = 0; i < len; i++)
		if (map[i] == person)
			return i;

	return -1;
}