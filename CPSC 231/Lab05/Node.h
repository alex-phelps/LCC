/**********************************************
 * Node.h
 * Written by Mark M Bowman
 **********************************************/

class node
{ friend void main();
  public:
    node(string="",int=0);      // Constructor with parameters
    ~node();                    // Destructor
    void append(node *p);       // Insert node at end of list
    void forwards(ostream &);   // Display list forwards
    void backwards(ostream &);  // Display list backwards
    void put(ostream &);        // Display node
  private:
    string name;                // Name
    int count;                  // Count
    node *next;                 // Next node pointer
};
