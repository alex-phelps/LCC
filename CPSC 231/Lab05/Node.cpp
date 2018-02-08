/**********************************************
 * Node.cpp
 * Alex Phelps
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Node.h"

/**********************************************
 * Constructor - parameters
 **********************************************/
node::node(string arg1,int arg2)
{ name = arg1;
  count = arg2;
  next = NULL;
  put(cerr);
}

/**********************************************
 * Destructor
 **********************************************/
node::~node()
{ put(cerr);
  if(next!=NULL) delete next;
}

/**********************************************
 * Append
 **********************************************/
void node::append(node *p)
{ if(next!=NULL)
    next->append(p);
  else
    next = p;
}

/**********************************************
 * Put to display
 **********************************************/
void node::put(ostream &out)
{ out << setiosflags(ios::left);
  out << setw(10) << this << "  ";
  out << setw(10) << name;
  out << setw(4) << count;
  out << setw(10) << next;
  out << endl;
}

//Prints linked list in order
void node::forwards(ostream &out)
{
	put(out);

	if (next != NULL)
		next->forwards(out);
}

//Prints linked list in reverse order
void node::backwards(ostream &out)
{
	if (next != NULL)
		next->backwards(out);
	put(out);
}