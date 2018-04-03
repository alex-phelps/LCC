/************************************
 * Node Answer.cpp
 * Updated by Alex Phelps
 ************************************/

#include <iostream>
#include <string>
using namespace std;

#include "Node.h"

/************************************
 * path()
 ************************************/
void node::path(string s)
{ 
	cout << val << " ";

	if (s == val) return; //End of path
	else if (s < val) //Left
		if (left != NULL)
			left->path(s);
		else
			cout << "Not Found"; //End, not in tree
	else //Right
		if (right != NULL)
			right->path(s);
		else
			cout << "Not Found"; //Also end, not in tree
}
