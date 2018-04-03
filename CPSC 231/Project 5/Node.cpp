#include "node.h"

node::node(string data)
{
	this->data = data;
	left = NULL;
	right = NULL;
}

//Deconstructor - deletes child nodes also
node::~node()
{
	if (left != NULL) delete left;
	if (right != NULL) delete right;
}

//Output to stream
void node::put(ostream &out)
{
	out << data << endl;
}

//Outputs left child, self, then right child
void node::LMR(ostream &out)
{
	if (left != NULL) left->LMR(out);
	put(out);
	if (right != NULL) right->LMR(out);
}