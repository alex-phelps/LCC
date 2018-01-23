//Project 2.cpp - Entry Point

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include "Person.h"
#include "Family.h"

#define SIZE 20 //arr size

using namespace std;

int main()
{
	Family family{SIZE};
	Person p;
	string fname;
	fstream file;

	cout << "File name: ";
	cin >> fname;

	//File input - opening file
	file.open(fname, ios::in);

	//input from file
	while (p.get(file)) family.insert(p);

	// close file
	file.close(); 
	
	cout << "--Unsorted--" << endl;
	family.display(cout);

	family.sort();
	cout << endl << "--Sorted--" << endl;
	family.display(cout);

	cout << family.length() << " objects" << endl;

	return 0;
}