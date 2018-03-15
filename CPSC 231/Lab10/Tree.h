// Tree Declarations

#define TREE_MAX  1024
#define TREE_ERR  -1

class tree
{ public:
    tree();                       // Constructor
    bool insert(string);          // Insert string into tree
    void dump();                  // Dump contents of array
    int  depth();                 // Total depth
    void show(string);            // Display in order
	int find(string);             // Finds string in tree
  private:
    string map[TREE_MAX];         // Data array
    int  left(int pos);           // Left child
    int  right(int pos);          // Right child
    int  depth_recurse(int pos);  // Recursive depth function
    void lmr(int pos);            // Recursive LMR display
	void rml(int pos);            // Recursive RML display
	void mlr(int pos);            // Recursive MLR display
};
