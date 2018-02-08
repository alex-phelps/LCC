/**********************************************
 * Lab 05
 * Alex Phelps
 **********************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"

/**********************************************
 * main
 **********************************************/
void main()
{ int count;
  string name;
  fstream infile;
  node *head,*p;

  head = NULL;

// Open file

  cout << "Enter file name: ";
  cin >> name;
  infile.open(name.data(),ios::in);

// Loop through file

  while(!infile.eof())
    { infile >> name >> count;

// Process valid input

      if(infile.good())
        { 
		  p = new node(name, count);
		  if (head == NULL)
			  head = p;
		  else
			  head->append(p);

        };
    };

// Close file

  infile.close();
  cout << endl;

  //Print list
  cout << "Forwards" << endl;
  if (head != NULL) head->forwards(cout);
  cout << endl;

  cout << "Backwards" << endl;
  if (head != NULL) head->backwards(cout);
  cout << endl;
  ////

  cout << "Finished!" << endl << endl;
  if (head != NULL) delete head;

}
