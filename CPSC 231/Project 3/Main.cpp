/***********************************
 * Program 03
 * Written by Mark M Bowman
 ***********************************/ 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "List.h"

void extra(list &);

/***********************************
 * Main
 * Test function - DO NOT CHANGE
 ***********************************/ 
void main()
{ int age;
  list a;
  node *p;
  string fname, first, last;
  fstream infile;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;
  //fname = "People.txt";
// Open file

  infile.open(fname,ios::in);

// Loop through file

  while(!infile.eof())
    { infile >> first >> last >> age;
    
// Process if okay

      if(infile.good())
        a.insert(first,last,age);
    };

// Close

  infile.close();
  cout << endl << a.length() << " nodes" << endl;

// Find node

  cout << endl;
  cout << "Enter First and Last name: ";
  cin >> first >> last;

  cout << endl << "Find: ";
  p = a.find(first,last);
  if(p!=NULL)
    { cout << "Found!" << endl;
      p->put(cout);
    }
  else
    cout << "Not found" << endl;

// Remove from list

  cout << endl << "Remove: ";
  if(a.remove(first,last))
    { cout << "Success!" << endl;
      cout << a.length() << " nodes" << endl;
    }
  else
    cout << "Fail" << endl;

// Display forwards

  cout << endl;
  cout << "Forwards List\n--------------\n";
  a.forwards(cout);
  cout << endl;

// Display backwards

  cout << "Backwards List\n--------------\n";
  a.backwards(cout);
  cout << endl;

// Extra credit

  extra(a);
}

/***********************************
 * Extra Credit
 * Test function - DO NOT CHANGE
 ***********************************/ 

void extra(list &a)
{ int i,n;
  node_ptr map[4];
  string first,last;

// Find node

  cout << endl;
  cout << "Enter First and Last name: ";
  cin >> first >> last;

  n = a.findall(first,last,map,4);

// Display forwards

  cout << endl;
  cout << "Find List\n--------------\n";
  for(i=0;i<n;i++)
    map[i]->put(cout);
}

