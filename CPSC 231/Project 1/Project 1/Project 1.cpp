// Project 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Person.h"

#define SIZE 20

using namespace std;

int main()
{
	Person people[SIZE];
	string fname;
	fstream file;

	cout << "File name: ";
	cin >> fname;

	file.open(fname, ios::in);

	int i = 0;
	while (!file.eof() || !file.good() || i < SIZE)
	{
		if (!people[i].Get(file)) break;
		i++;
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

