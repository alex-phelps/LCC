/************************************
 * Lab11.cpp
 * Written by Mark M Bowman
 ************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"

/*******************************
  Main program
 *******************************/
void main()
{ int value;
  string fname;
  fstream in;
  node *root;

// Initialize

  root = NULL;

// Get user input

  cout << "Enter file name: ";
  cin >> fname;
  cout << endl;

// Open file

  in.open(fname.data(),ios::in);

// Loop through file

  while(!in.eof())
    { in >> value;
      
// Process if good

      if(in.good())
        {

// Start tree at root

          if(root==NULL)
            root = new node(value);

// Add to tree

          else
            root->insert(value);
        };
    };

// Close file

  in.close();

///* PART 1
// Display tree

  cout << "Entire Tree" << endl;
  root->lmr();
  cout << endl << endl;
//*/

///* PART 2
// Display leaves

  cout << "Leaves" << endl;
  root->leaves();
  cout << endl << endl;
//*/

///* PART 3
// Display leaves and depth

  cout << "Leaf   Depth" << endl;
  cout << "-----  -----" << endl;
  root->leaves(0);
  cout << endl;
//*/

// Clean up

  if(root!=NULL) delete root;
}
