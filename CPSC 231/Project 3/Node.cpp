#include "node.h"
#include <iostream>
#include <iomanip>

using namespace std;

node::node()
{
	next = NULL;
}

node::~node()
{
	if (next != NULL)
		delete next;
}

void node::put(ostream &out)
{
	out << left;
	out << setw(16) << last;
	out << setw(10) << first;
	out << age << endl;
}

void node::fore(ostream &out)
{
	put(out);
	if (next != NULL)
		next->fore(out);
}

void node::back(ostream &out)
{
	if (next != NULL)
		next->fore(out);
	put(out);
}

bool node::operator==(const node &n)
{
	return first == n.first && last == n.last;
}

bool node::operator<(const node &n)
{
	return last < n.last || (last == n.last && (first < n.first || (first == n.first && age < n.age)));
}

bool node::operator>(const node &n)
{
	return last > n.last || (last == n.last && (first > n.first || (first == n.first && age > n.age)));
}