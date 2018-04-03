#pragma once
#include "node.h"

class tree
{
public:
	tree();
	~tree();
	void insert(string);
	void show(string, ostream &out);
	bool find(string);
	bool remove(string);
	int count();
	int depth();

private:
	node* remove(node*, string);

	node* root;
};