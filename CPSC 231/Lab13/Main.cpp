/************************************
 * Lab13.cpp
 * Written by YOUR NAME GOES HERE
 ************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define ARRAY_MAX  1000

#include "Heapsort.h"

/******************************
 * main()
 ******************************/
void main()
{ int i,n;
  string fname,name,map[ARRAY_MAX];
  fstream in;

// Initialize

  n = 0;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;

// Read from file

  in.open(fname.data(),ios::in);
  if(!in.is_open()) return;

// Loop through file

  while(!in.eof())
    { in >> name;
      if(in.good()) map[n++] = name;
      //if(in.good()) heap_insert(map,n,name);
   };

// Close file

  in.close();

// Display array

  cout << endl;
  cout << "Array" << endl << "----------------" << endl;

  for(i=0;i<n;i++)
    cout << map[i] << " ";
  cout << endl;

  //Heapify
  heapify(map, n);

  //Display array

  cout << endl;
  cout << "Heapified Array" << endl << "----------------" << endl;

  for (i = 0; i<n; i++)
	  cout << map[i] << " ";
  cout << endl;

  //Remove
  heap_sort(map, n);

  //Display array

  cout << endl;
  cout << "Sorted" << endl << "----------------" << endl;

  for (i = 0; i<n; i++)
	  cout << map[i] << " ";
  cout << endl;
}
