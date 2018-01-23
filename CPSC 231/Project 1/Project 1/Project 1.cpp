// Project 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include "Person.h"

#define SIZE 20 //arr size

using namespace std;

void sort(Person* people, int size);

int main()
{
	Person people[SIZE];
	string fname;
	fstream file;

	cout << "File name: ";
	cin >> fname;

	//File input
	file.open(fname, ios::in);

	int i = 0;
	while (!file.eof() || !file.good() || i < SIZE)
	{
		if (!people[i].Get(file)) break;
		i++;
	}
	file.close();
	//

	//Sort
	sort(people, SIZE);

	//Display
	cout << "Last          First     Age" << endl;
	cout << "------------  --------  ---" << endl;
	for (auto& person : people)
		person.Put(cout);

	return 0;
}

//Sorts array of people - yay bubble sort
void sort(Person* people, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (people[j] > people[j + 1])
			{
				swap(people[j], people[j + 1]);
			}
		}
	}
}