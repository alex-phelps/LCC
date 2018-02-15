#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Bin.h"

/**************************************
 * Constructor - no parameters
 **************************************/
bin::bin()
{ name = "";
  count = 0;
}

/**************************************
 * Get
 **************************************/
bool bin::get(istream &in)
{ in >> name;
  in >> count;
  return in.good();
}

/**************************************
 * Put
 **************************************/
void bin::put(ostream &out)
{ out << left;
  out << setw(16) << name;
  out << setw(4) << count;
}

//Operators
bool bin::operator== (const bin &b)
{
	return count == b.count && name == b.name;
}

bool bin::operator> (const bin &b)
{
	return name > b.name || (name == b.name && count > b.count);
}

bool bin::operator< (const bin &b)
{
	return name < b.name || (name == b.name && count < b.count);
}