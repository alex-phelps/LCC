/***************************************
 * Lab 04a - Recursion
 * Written 23-Sep-14 by YOUR NAME
 ***************************************/

#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;

void apple(string s);

int counter = 0;

/***************************************
 * Main
 ***************************************/
void mainv()
{ string name;

// Get user input

  cout << "Enter your last name: ";
  cin >> name;

// Call recursive function

  cout << endl;
  apple(name);
  cout << endl;

// Output results
 
  cout << counter << " recursions\n";
}

/***************************************
 * Apple
 ***************************************/
void apple(string s)
{ int i;

  counter++;

// Return if at end of characters

  if(s.length()==0) return;

// Get ascii value

  i = (int)s.at(0);

  // Recurse on next char

  apple(s.substr(1, s.length() - 1));

// Output value

  cout << s.at(0);
}
