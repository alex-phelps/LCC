// Project 1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "stdafx.h"
#include "Person.h"

#define SIZE 20

int main()
{
	Person people[SIZE];
	string fname;
	fstream file;

	cout << "File name: ";
	cin >> fname;

	file.open(fname, ios::in);
	if (!file.is_open()) return 1;

	for (int i = 0; i < SIZE; i++)
	{
		if (file.eof() || !file.good()) break;
		people[i].Get(file);
	}
	file.close();

	sort(people, people + SIZE);

	cout << "Last          First     Age" << endl;
	cout << "------------  --------  ---" << endl;
	for (auto& person : people)
	{
		person.Put(cout);
	}

    return 0;
}

