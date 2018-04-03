/************************************
 * Node Answers.cpp
 * Updated by Alex Phelps
 ************************************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "Node.h"

//Prints left child, then self, then right child (recursively)
void node::lmr()
{
	if (left != NULL) left->lmr(); // left
	cout << val << ' '; // print self
	if (right != NULL) right->lmr(); // right
}

//Prints only leaves
void node::leaves()
{
	bool leaf = true;

	if (left != NULL)
	{
		leaf = false;
		left->leaves(); //recurse left
	}

	if (right != NULL)
	{
		leaf = false;
		right->leaves(); //recurse right
	}

	if (leaf) cout << val << ' '; //if this is a leaf, print
}

//Prints leaves and their depth
void node::leaves(int depth)
{
	bool leaf = true;

	if (left != NULL)
	{
		leaf = false;
		left->leaves(depth + 1); //recurse left, add to depth
	}

	if (right != NULL)
	{
		leaf = false;
		right->leaves(depth + 1); //recurse right, add to depth
	}

	if (leaf) cout << setw(5) << val << "  " << setw(5) << depth << endl; //if this is a leaf, print
}