#include <iostream>
using namespace std;

#include "Box.h"

/**************************************
 * Constructor
 **************************************/
box::box(int h,int w)
{ //cout << "Box " << this << " created\n";
  height = h;
  width = w;
}

/**************************************
 * Destructor - optional
 **************************************/
box::~box()
{ //cout << "Box " << this << " destroyed\n";
}

/**************************************
 * Get
 **************************************/
bool box::get(istream &in)
{ in >> height;
  in >> width;
  return in.good();
}

/**************************************
 * Put
 **************************************/
void box::put(ostream &out)
{ out << height << 'X' << width;
}


bool box::operator==(const box &b)
{
	return height == b.height && width == b.width;
}