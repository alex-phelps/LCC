/*********************************
 * Bushel header
 * Created by Mark Bowman
 *********************************/

#include <iostream>
using namespace std;

class bushel
{ 
public:
    bushel();              // Constructor - empty
    bushel(int,int);       // Constructor with counts
    bool get(istream &);   // Input
    void put(ostream &);   // Output
private:
    int apples;            // Apples in bushel
    int oranges;           // Oranges in bushel 

friend bool operator == (const bushel &a, const bushel &b);
friend bool operator > (const bushel &a, const bushel &b);
friend bool operator < (const bushel &a, const bushel &b);

friend bool operator == (const bushel &a, const int &b);
friend bool operator > (const bushel &a, const int &b);
friend bool operator < (const bushel &a, const int &b);
};
