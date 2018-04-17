#pragma once

#define EDGE_MAX 8

#include <string>
#include <iostream>

using namespace std;

class node {
friend class graph;
public:
	node();
	node(string);
	void put(ostream &out);
	void connect(node*, int);
	void depth(ostream &out);
	void breadth(node**, int &count);
	string value;
private:
	bool visit;
	node *edge[EDGE_MAX];
	int distance[EDGE_MAX];
};