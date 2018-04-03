/************************************
 * Node.cpp
 * Updated by YOUR NAME GOES HERE
 ************************************/

#include <iostream>
#include <string>
using namespace std;

#include "Node.h"

/*******************************
 * Constructor
 *******************************/
node::node(string arg)
{ val = arg;
  left = right = NULL;
}

/*******************************
 * Destructor
 *******************************/
node::~node()
{ if(left!=NULL) delete left;
  if(right!=NULL) delete right;
}

/*******************************
 * insert()
 *******************************/
void node::insert(string arg)
{

// Left side

  if(arg<=val)
    { 

// Recurse left

      if(left!=NULL)
        left->insert(arg);

// Add node here

      else
        left = new node(arg);
     }

// Right side

   else
     { 

// Recurse right

       if(right!=NULL)
         right->insert(arg);

// Add node here

       else
         right = new node(arg);
     };
}

/*******************************
 * lmr()
 *******************************/
void node::lmr()
{ if(left!=NULL) left->lmr();
  cout << val << endl;
  if(right!=NULL) right->lmr();
}
