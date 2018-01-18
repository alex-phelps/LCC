/*********************************
 * Lab 02
 * Created by Alex Phelps
 *********************************/

#include <iostream>
using namespace std;

#include "Bushel.h"

// Main program

void main()
{ class bushel a,b,c;

// Initialize bushels

  a = bushel(3,8);
  b = bushel(2,6);

// Step 9
// Get bushels

  cout << "Enter bushel A (apples,oranges):";
  a.get(cin);
  cout << "Enter bushel B (apples,oranges):";
  b.get(cin);


// Output bushels

  cout << "A: ";  a.put(cout);  cout << endl;
  cout << "B: ";  b.put(cout);  cout << endl;

// Step 4
// Bushel compare 1

  if(a == b)
    cout << "Bushel A == B" << endl;
  else
    cout << "Bushel A != B" << endl;


// Step 6
// Bushel compare 2

  if(a < b)
    cout << "Bushel A < B" << endl;
  else if(a > b)
    cout << "Bushel A > B" << endl;
  else
    cout << "Bushel A ? B" << endl;

  cout << endl;

  //step 10

  int total;
  cout << "Enter Total: ";
  cin >> total;
  cout << endl;

  if (a > total)
	  cout << "Bushel A > " << total << endl;
  else if (a < total)
	  cout << "Bushel A < " << total << endl;
  else cout << "Bushel A == " << total << endl;

  if (b > total)
	  cout << "Bushel B > " << total << endl;
  else if (b < total)
	  cout << "Bushel B < " << total << endl;
  else cout << "Bushel B == " << total << endl;

}