#include <iostream>
#include <string>

using namespace std;

/***********************************
 * Node declaration
 * DO NOT CHANGE
 ***********************************/

class list;

class node
{ friend list;
  public:
    node();                           // Null constructor
    ~node();                          // Destructor 
    void put(ostream &out);           // Put
    void fore(ostream &out);          // Output list forwards
    void back(ostream &out);          // Output list backwards
    bool operator == (const node &);  // Equal
    bool operator < (const node &);   // Less than
    bool operator > (const node &);   // Greater than
  private:
    string first, last;
    int age;
    node *next;
};

typedef node * node_ptr;
