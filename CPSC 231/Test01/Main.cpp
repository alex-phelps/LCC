/*********************************
 * Test 01
 * Created by YOUR NAME HERE
 *********************************/

#include <iostream>
using namespace std;

#include "Bag.h"

/*********************************
 * main()
 *********************************/
void main()
{ class bag a,b,c;

// Initialize bags

  a = bag(3,8,1,4,5);
  b = bag(2,6,0,4,5);

// Add bags

  c = a+b;

// Output bags

  cout << "A: ";  a.put(cout);  cout << endl;
  cout << "B: ";  b.put(cout);  cout << endl;
  cout << "C: ";  c.put(cout);  cout << endl;
}