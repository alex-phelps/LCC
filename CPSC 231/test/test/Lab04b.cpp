/***************************************
 * Lab 04b – Recursive Factorial
 * Written by Alex Phelps
 ***************************************/

#include "stdafx.h"

#include <iostream>
using namespace std;

int factor(int);

/***************************************
 * Main
 ***************************************/
void main()
{ int f,n;

// Get user input

  cout << "Enter an integer: ";
  cin >> n;

// Call factorial function

  f = factor(n);

// Output results
 
  cout << n << "! = " << f << endl;
}

//Returns the factorial of and integer
int factor(int f)
{
	if (f < 0) return -1; // no natural factorial of negative numbers
	else if (f < 2) return 1; // factorial of 0 and 1 are defined as 1

	return factor(f - 1) * f; // recurse
}
