/*********************************
 * Test 04
 * Created by Alex Phelps
 *********************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#include "Heap.h"

/*********************************
 * main()
 *********************************/
void main()
{ string fname,s;
  fstream infile;
  heap<string> h;

// Open file

  cout << "Enter file name: ";
  cin >> fname;
  infile.open(fname.data(),ios::in);
  if(!infile.is_open()) return;
  cout << endl;

// Read data from file

  while(!infile.eof())
    { infile >> s;

// Process if input is valid

      if(infile.good())
        { h.insert(s);
        };
    };

// Close file

  infile.close();

// Display table

  h.dump(cout);
  cout << endl;

/*** Extra Credit
// Remove items from table

  while(h.size()>0)
    cout << h.remove() << endl;
***/
}
