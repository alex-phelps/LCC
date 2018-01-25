//Project 2.cpp - Entry Point
// By Alex Phelps

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include "Person.h"
#include "Family.h"

#define SIZE 20 //arr size

using namespace std;

int main()
{
	Family family;
	Person p;
	fstream file;
	string fname;

	cout << "Enter file name: ";
	cin >> fname;

	//File input - opening file
	file.open(fname, ios::in);

	//input from file
	while (!file.eof())
	{
		p.get(file);
		family.insert(p);
	}

	// close file
	file.close(); 
	
	//original
	cout << "--Unsorted--" << endl;
	family.display(cout);

	//test sort()
	family.sort();
	cout << endl << "--Sorted--" << endl;
	family.display(cout);
	cout << endl;

	//test length()
	cout << family.length() << " objects" << endl;

	//Test find() function
	cout << "Find \"Bowman, David\" = " << family.find("David", "Bowman") << endl;
	cout << "Find \"Bowman, Mark\" = " << family.find("Mark", "Bowman") << endl;
	cout << "Find \"Morales, Carlos\" = " << family.find("Carlos", "Morales") << endl;
	cout << "Find \"Claus, Santa\" = " << family.find("Santa", "Claus") << endl;
	cout << endl;

	//test remove()
	family.remove("David", "Bowman");
	family.remove("Mark", "Bowman");
	cout << endl << "--Edited List--" << endl;
	family.display(cout);
	cout << endl << family.length() << " objects" << endl; //final count

	return 0;
}