#include "node.h"
#include <iostream>
#include <iomanip>

using namespace std;

node::node()
{
}

node::~node()
{
	if (next != NULL)
		delete next;
}

void node::put(ostream &out)
{
	out << setw(16) << last;
	out << setw(10) << first;
	out << age << endl;
}

void node::fore(ostream &out)
{
	put(out);
	if (next != NULL)
		next->put(out);
}

void node::back(ostream &out)
{
	if (next != NULL)
		next->put(out);
	put(out);
}

bool node::operator==(const node &n)
{
	return first == n.first && last == n.last;
}

bool node::operator<(const node &n)
{
	return first < n.first || (first == n.first && (last < n.last || (last == n.last && age < n.age)));
}

bool node::operator>(const node &n)
{
	return first > n.first || (first == n.first && (last > n.last || (last == n.last && age > n.age)));
}