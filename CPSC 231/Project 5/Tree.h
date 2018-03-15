#pragma once
#include "node.h"

class tree
{
public:
	tree();
	~tree();
	bool insert(string);
	void show(string, ostream &out);
	bool find(string);

private:
	node* root;
};