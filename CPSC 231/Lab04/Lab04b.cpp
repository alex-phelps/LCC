/***************************************
 * Lab 04b – Recursive Factorial
 * Written by YOUR NAME
 ***************************************/

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
