// Tree Functions

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "Tree.h"

/****************************
 * left()
 ****************************/
int tree::left(int pos)
{ return pos*2+1;
}

/****************************
 * right()
 ****************************/
int tree::right(int pos)
{ return (pos+1)*2;
}

/****************************
 * depth()
 ****************************/
int tree::depth_recurse(int pos)
{ int l,r;

// Return if bottom or empty node

  if(pos>=TREE_MAX) return 0;
  if(map[pos]=="") return 0;

// Left,Right

  l = depth_recurse(left(pos));
  r = depth_recurse(right(pos));  

// Max of both sides + middle

  return max(l,r)+1;
}

/****************************
 * lmr()
 ****************************/
void tree::lmr(int pos)
{ 
	if (pos > TREE_MAX || map[pos] == "") return;

	lmr(left(pos));
	cout << map[pos] << endl;
	lmr(right(pos));
}

/****************************
* rml()
****************************/
void tree::rml(int pos)
{
	if (pos > TREE_MAX || map[pos] == "") return;

	rml(right(pos));
	cout << map[pos] << endl;
	rml(left(pos));
}

/****************************
* mlr()
****************************/
void tree::mlr(int pos)
{
	if (pos > TREE_MAX || map[pos] == "") return;

	cout << map[pos] << endl;
	mlr(left(pos));
	mlr(right(pos));
}
