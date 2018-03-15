#include "tree.h"

tree::tree()
{
	root = NULL;
}

tree::~tree()
{
	delete root;
}

bool tree::insert(string data)
{
	if (root == NULL)
	{
		root = new node(data);
		return true;
	}

	node *p = root;

	while (p != NULL)
	{
		if (data < p->data)
		{
			if (p->left == NULL)
			{
				p->left = new node(data);
				return true;
			}
			else p = p->left;
		}
		else
		{
			if (p->right == NULL)
			{
				p->right = new node(data);
				return true;
			}
			else p = p->right;
		}
	}

	return false;
}

void tree::show(string order, ostream &out)
{
	if (root == NULL) return; //nothing to show

	if (order == "LMR")
		root->LMR(out);
}

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