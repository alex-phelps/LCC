/*********************************
 * Bushel code
 * Created by Mark Bowman
 *********************************/

#include <iostream>
using namespace std;

#include "Bushel.h"

/**********************************
 * Bushel
 **********************************/
bushel::bushel(int a,int o)
{ apples = a;
  oranges = o;
}

/**********************************
 * Get
 **********************************/
bool bushel::get(istream &in)
{ in >> apples >> oranges;
  return(in.good());
}

/**********************************
 * Put
 **********************************/
void bushel::put(ostream &out)
{ out << apples << " Apples ";
  out << oranges << " Oranges";
}


bool bushel::operator==(const bushel &b)
{
	return apples == b.apples && oranges == b.oranges;
}