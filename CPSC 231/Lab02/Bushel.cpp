/*********************************
 * Bushel code
 * Created by Mark Bowman
 *********************************/

#include <iostream>
using namespace std;

#include "Bushel.h"

// Bushel contructor - empty

bushel::bushel()
{ apples = 0;
  oranges = 0;
}

// Bushel contructor with counts

bushel::bushel(int a,int o)
{ apples = a;
  oranges = o;
}

// Bushel input

bool bushel::get(istream &in)
{ in >> apples >> oranges;
  return(in.good());
}

// Bushel output

void bushel::put(ostream &out)
{ out << apples << " Apples ";
  out << oranges << " Oranges";
}

//overloading operators
bool operator == (const bushel &a, const bushel &b)
{
	return (a.apples == b.apples && b.oranges == b.oranges);
}

bool operator < (const bushel &a, const bushel &b)
{
	return (a.apples < b.apples && a.oranges < b.oranges);
}

bool operator > (const bushel &a, const bushel &b)
{
	return (a.apples > b.apples && a.oranges > b.oranges);
}

bool operator == (const bushel &a, const int &b)
{
	return (a.apples + a.oranges) == b;
}

bool operator < (const bushel &a, const int &b)
{
	return (a.apples + a.oranges) < b;
}

bool operator > (const bushel &a, const int &b)
{
	return (a.apples + a.oranges) > b;
}