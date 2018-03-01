/*********************************
 * Node class declaration
 *********************************/

class node
{ public:
    node(int arg1=0,string arg2="",string arg3="");  // Constructor
    void put(ostream &out);                          // Put data
  private:
    int id;                                          // ID number
    string first,last;                               // First and Last names
};
