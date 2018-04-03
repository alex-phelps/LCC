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

//Inserts node beginning at this current node
void node::insert(node* n)
{
	if (n->data < data)
		if (left != NULL)
			left->insert(n);
		else left = n;
	else if (right != NULL)
		right->insert(n);
	else right = n;
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

//Right, Middle, Left
void node::RML(ostream &out)
{
	if (right != NULL) right->RML(out);
	put(out);
	if (left != NULL) left->RML(out);
}

//Middle, Left, Right
void node::MLR(ostream &out)
{
	put(out);
	if (left != NULL) left->MLR(out);
	if (right != NULL) right->MLR(out);
}

//Counts nodes below this one
int node::count()
{
	int count = 1; //self
	if (left != NULL) count += left->count();
	if (right != NULL) count += right->count();

	return count;
}

//Gives depth relative to this this node
int node::depth()
{
	int l = left != NULL ? 1 + left->depth() : 0; //if theres is a child, add their depth + 1 (the addition is here because a single node is depth 0)
	int r = right != NULL ? 1 + right->depth() : 0;

	return l > r ? l : r; //return max of left and right depths
}