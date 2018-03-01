/*********************************
 * Node class definitions
 *********************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Node.h"

/*********************************
 * node::set()
 *********************************/
node::node(int arg1,string arg2,string arg3)
{ id = arg1;
  first = arg2;
  last = arg3;
}

/*********************************
 * node::put()
 *********************************/
void node::put(ostream &out)
{ out << setw(8) << id;
  out << setw(8) << first;
  out << setw(16) << last;
}
