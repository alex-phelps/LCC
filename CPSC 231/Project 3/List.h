#pragma once
#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

class list
{
public:
	list();
	~list();
	void insert(string, string, int);
	node* find(string, string);
	bool remove(string, string);
	void forwards(ostream &out);
	void backwards(ostream &out);
	int length();

private:
	node* head;
};