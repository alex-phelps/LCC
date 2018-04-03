#pragma once
#include <iostream>
#include <string>

using namespace std;

class node
{
friend class tree;

public:
	node(string);
	~node();
	void insert(node*);
	void put(ostream &out);
	void LMR(ostream &out);
	void RML(ostream &out);
	void MLR(ostream &out);
	int count();
	int depth();

private:
	string data;
	node *left, *right;
};