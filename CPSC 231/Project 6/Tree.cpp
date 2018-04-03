#include "tree.h"

tree::tree()
{
	root = NULL;
}

tree::~tree()
{
	if (root != NULL)
		delete root;
}

//Add new string to the tree; sort at input
void tree::insert(string data)
{
	// OLD - Project 5 code
	//if (root == NULL)
	//{
	//	root = new node(data);
	//	return true;
	//}

	//node *p = root;

	//while (p != NULL)
	//{
	//	if (data < p->data)
	//	{
	//		if (p->left == NULL)
	//		{
	//			p->left = new node(data);
	//			return true;
	//		}
	//		else p = p->left;
	//	}
	//	else
	//	{
	//		if (p->right == NULL)
	//		{
	//			p->right = new node(data);
	//			return true;
	//		}
	//		else p = p->right;
	//	}
	//}

	//return false;


	//NEW CODE
	if (root == NULL)
		root = new node(data);
	else root->insert(new node(data));
}

//Output in specific order
void tree::show(string order, ostream &out)
{
	if (root == NULL) return; //nothing to show

	if (order == "LMR")
		root->LMR(out);
	else if (order == "RML")
		root->RML(out);
	else if (order == "MLR")
		root->MLR(out);
}

//Returns true if string is found in the tree
bool tree::find(string data)
{
	node *p;
	p = root;
	while (p != NULL)
	{
		if (p->data == data) return true;
		else if (data < p->data) p = p->left;
		else p = p->right;
	}

	return false;
}

//Removes a string from the tree; true is successful
bool tree::remove(string data)
{
	if (remove(root, data) == NULL)
		return false;
	else return true;
}

//Removes a node and returns new structure
node* tree::remove(node* base, string data)
{
	//Base case
	if (base == NULL)
		return base;

	if (data < base->data)
		root->left = remove(base->left, data);
	else if (data > base->data)
		root->right = remove(base->right, data);
	else
	{
		//Check if only one child (or none)
		if (base->left == NULL)
		{
			node *temp = base->right;
			base->right = NULL;
			delete base;
			return temp;
		}
		else if (base->right == NULL)
		{
			node *temp = base->left;
			base->left = NULL;
			delete base;
			return temp;
		}

		//Two children, add right tree to left tree (not that efficient though)
		node *temp = base->left;
		temp->insert(base->right);
		delete base;
		return temp;
	}

	return base;
}

//Counts node in the tree
int tree::count() 
{
	if (root != NULL)
		return root->count();
	else return 0;
}

//Gives depth of the tree
int tree::depth()
{
	if (root != NULL)
		return root->depth();
	else return -1; //no nodes, invalid depth
}