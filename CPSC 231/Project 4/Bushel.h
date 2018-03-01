/*********************************
 * Bushel header
 * Created by Mark Bowman
 *********************************/

#include <iostream>
using namespace std;

class bushel
{ public:
    bushel(int a=0,int o=0);    // Constructor
    bool get(istream &);        // Input
    void put(ostream &);        // Output
	bool operator==(const bushel &b);
  private:
    int apples;                 // Apples in bushel
    int oranges;                // Oranges in bushel 
};
