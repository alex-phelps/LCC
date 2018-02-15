/**********************************************
 * Lab 06
 * Alex Phelps
 **********************************************/
#include <iostream>
#include <string>
#include "bin.h"
using namespace std;

//Sorts three objects
template <class T>
void mini_sort(T &i, T &j, T &k)
{
	if (i > k) swap(i, k);
	if (i > j) swap(i, j);
	if (j > k) swap(j, k);
}

/**********************************************
 * main()
 **********************************************/
 void main()
{ int i,j,k;
  string a,b,c;
  bin b1, b2, b3;

// Get 1st user entry

  cout << "Enter three integers: ";
  cin >> i >> j >> k;

// Mini-sort

  mini_sort(i,j,k);

// Display

  cout << i << " < ";
  cout << j << " < ";
  cout << k << endl << endl;

// Get 2nd user entry

  cout << "Enter three names: ";
  cin >> a >> b >> c;

// Mini-sort

  mini_sort(a,b,c);

// Display

  cout << a << " < ";
  cout << b << " < ";
  cout << c << endl << endl;

  cout << "Enter bin 1: ";
  b1.get(cin);
  cout << "Enter bin 2: ";
  b2.get(cin);
  cout << "Enter bin 3: ";
  b3.get(cin);

  mini_sort(b1, b2, b3);

  b1.put(cout); cout << " < ";
  b2.put(cout);  cout << " < ";
  b3.put(cout);  cout << endl << endl;
}

