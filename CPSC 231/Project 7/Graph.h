#pragma once

#define GRAPH_MAX 20

#include <string>
#include <iostream>
#include "Node.h"

using namespace std;

class graph {
public:
	graph();
	bool insert(string, string, int);
	void depth(ostream &out, string);
	void breadth(ostream &out, string);
	int find(string);
private:
	void clear();
	node map[GRAPH_MAX];
	int n;
};