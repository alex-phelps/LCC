#include "node.h"

node::node(string data)
{
	this->data = data;
	left = NULL;
	right = NULL;
}

node::~node()
{
	if (left != NULL) delete left;
	if (right != NULL) delete right;
}

void node::put(ostream &out)
{
	out << data << endl;
}

void node::LMR(ostream &out)
{
	if (left != NULL) left->put(out);
	put(out);
	if (right != NULL) right->put(out);
}