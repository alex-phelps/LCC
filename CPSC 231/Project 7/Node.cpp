#include "Node.h"
#include "Graph.h"

node::node()
{
	int i;
	for (i = 0; i < EDGE_MAX; i++)
		edge[i] = NULL;
}

node::node(string value) : node()
{
	this->value = value;
}

//Output to stream
void node::put(ostream &out)
{
	out << value << endl;
}

//Creates a connection to another node
void node::connect(node* n, int w)
{
	int i;
	for (i = 0; i < EDGE_MAX; i++) //Find NULL value, inster connection
		if (edge[i] == NULL)
		{
			edge[i] = n;
			distance[i] = w;
			return;
		}
}

//Display depth first
void node::depth(ostream &out)
{
	visit = true;
	put(out);

	int i;
	for (i = 0; i < EDGE_MAX; i++)
	{
		if (edge[i] != NULL && !edge[i]->visit) //Skip if null or if visisted
			edge[i]->depth(out);
	}
}

//Display depth first
void node::breadth(node** map, int &count)
{
	visit = true;

	int i;
	for (i = 0; i < EDGE_MAX; i++)
		if (edge[i] != NULL && !edge[i]->visit && count < GRAPH_MAX)
		{
			map[count] = edge[i];
			count++;
		}
}