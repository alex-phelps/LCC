/************************************
 * Node.cpp
 * Written by Mark M Bowman
 ************************************/

#include <iostream>
using namespace std;

#include "Node.h"

/*******************************
 * Constructor
 *******************************/
node::node(int arg1)
{ val = arg1;
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
void node::insert(int arg)
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
