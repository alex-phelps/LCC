#include "Graph.h"

graph::graph()
{
	n = 0;
}

//Creates a connection between two given values in the graph; returns true if successful
bool graph::insert(string a, string b, int weight)
{
	int v_a = find(a); // a index
	int v_b = find(b); // b index

	if (v_a == -1) //does not exist in array
	{
		if (n >= GRAPH_MAX) return false; // array is full
		n++;
		map[n] = node(a); // new node
		v_a = n;
	}

	if (v_b == -1)
	{
		if (n >= GRAPH_MAX) return false; // full
		n++;
		map[n] = node(b); // new
		v_b = n;
	}

	map[v_a].connect(&map[v_b], weight); // create connection
	return true;
}

//Displays depth first
void graph::depth(ostream &out, string start)
{
	clear();

	int i = find(start); // find value
	if (i != -1) // only run on actual index
		map[i].depth(out);
}

//Displays breadth first
void graph::breadth(ostream &out, string start)
{
	clear();

	node *display[GRAPH_MAX]; // array to hold nodes to display in order
	int count = 0; //display count
	int i = find(start); // index of start node

	if (i == -1) return; // make sure start exists

	display[count] = &map[i]; //first in list
	count++;
		
	int d = 0;
	for (d = 0; d < count; d++)
	{
		if (!display[d]->visit) // not visited already
			display[d]->breadth(display, count); // will add edges to list and mark self visited
	}

	for (d = 0; d < count; d++) //display
		display[d]->put(out);
}

//Returns index of given value in graph; -1 if not found
int graph::find(string value)
{
	int i;
	for (i = 0; i < n; i++)
		if (map[i].value == value)
			return i;

	return -1;
}

//Clears visited status from nodes
void graph::clear()
{
	int i;
	for (i = 0; i < n; i++)
		map[i].visit = false;
}