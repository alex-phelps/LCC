/*********************************
 * Bag code
 * Created by Mark Bowman
 *********************************/

#include <iostream>
using namespace std;

#include "Bag.h"

/*********************************
 * Constructor
 *********************************/
bag::bag(int r,int y,int g,int b,int p)
{ color[Red]    = r;
  color[Yellow] = y;
  color[Green]  = g;
  color[Blue]   = b;
  color[Purple] = p;
}

/*********************************
 * Input
 *********************************/
bool bag::get(istream &in)
{ int i,val;
  for(i=0;i<BAG_COLOR_MAX;i++)
    { in >> val;
      color[i] = val;
    };
  return in.good();
}

/*********************************
 * Output
 *********************************/
void bag::put(ostream &out)
{ out << color[Red] << " Red ";
  out << color[Yellow] << " Yellow ";
  out << color[Green] << " Green ";
  out << color[Blue] << " Blue ";
  out << color[Purple] << " Purple ";
}

//Overload + to allow adding of bags together
bag bag::operator+ (const bag &b)
{
	color[Red] += b.color[Red];
	color[Yellow] += b.color[Yellow];
	color[Green] += b.color[Green];
	color[Blue] += b.color[Blue];
	color[Purple] += b.color[Purple];

	return *this;
}