/***********************************
 * Lab 01 Box driver
 * Written by Mark Bowman 09-Nov-06
 * Updated by Alex Phelps
 ***********************************/

#include <iostream>
using namespace std;

#include "Box.h"

/***********************************
 * Main()
 ***********************************/
void main()
{ class box a,b,c;

// Display empty boxes

  cout << "a = "; a.put(cout); cout << endl;
  cout << "b = "; b.put(cout); cout << endl;
  cout << "c = "; c.put(cout); cout << endl;
  cout << endl;

// Initialize with user input

  cout << "Enter box a: ";
  a.get(cin);
  cout << "Enter box b: ";
  b.get(cin);
  cout << endl;

// Display boxes

  cout << "a = "; a.put(cout); cout << endl;
  cout << "Area of a = " << a.area() << endl;
  cout << "b = "; b.put(cout); cout << endl;
  cout << "Area of b = " << b.area() << endl;
  cout << endl;
}