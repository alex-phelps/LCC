/************************************
 * Lab14.cpp
 * Written by YOUR NAME GOES HERE
 ************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Node Declarations

#define ERR       -1
#define NODE_MAX  20
#define EDGE_MAX  4

// Node class

class node
{ public:
    node();                  // Constructor
    void set_value(string);  // Set string value
    string get_value();      // Return string value
    void connect(node *);    // Connect this node to another
    void put(ostream &);     // Output node and neighbors
  private:
    string value;            // Node value
    node *edge[EDGE_MAX];    // Edges array
};

/******************************
 * main()
 ******************************/
void main()
{ int i,n;
  int source_index,target_index,distance;
  string fname,source_name,target_name;
  fstream in;
  node map[NODE_MAX];

// Initialize

  n = 0;
  cout << left;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;

// Open file

  in.open(fname,ios::in);

// Loop through file

  while(!in.eof())
    { in >> source_name >> target_name >> distance;
      
// Add to array 

      if(in.good())
        { 
		  //Output
		  //cout << setw(10) << source_name;
          //cout << setw(10) << target_name;
          //cout << setw(4) << distance;
          //cout << endl;

		  // Find/add source
		  source_index = -1;
		  for (int i = 0; i < n; i++)
			  if (map[i].get_value() == source_name)
			  {
				  source_index = i;
				  break;
			  }

		  if (source_index == -1) // not found
		  {
			  map[n].set_value(source_name);
			  source_index = n;
			  n++;
		  }
		  //

		  // Find/add target
		  target_index = -1;
		  for (int i = 0; i < n; i++)
			  if (map[i].get_value() == target_name)
			  {
				  target_index = i;
				  break;
			  }

		  if (target_index == -1) // not found
		  {
			  map[n].set_value(target_name);
			  target_index = n;
			  n++;
		  }
		  //

		  map[source_index].connect(&(map[target_index]));
        }; 
    };
 
// Close file

  in.close();

// Display array

  for(i=0;i<n;i++)
    map[i].put(cout);
}

/******************************
 * Null constructor
 ******************************/
node::node()
{ int i;
  value = "";
  for(i=0;i<EDGE_MAX;i++)
    edge[i] = NULL;
}

/******************************
 * set_value()
 ******************************/
void node::set_value(string arg)
{ value = arg;
}

/******************************
 * get_value()
 ******************************/
string node::get_value()
{ return value;
}

//Connects an edge
void node::connect(node *target)
{
	int i;
	for (i = 0; i < EDGE_MAX; i++)
		if (edge[i] == NULL)
		{
			edge[i] = target;
			return;
		}
}

//Outputs node
void node::put(ostream &out)
{
	int i;

	out << value << endl;
	for (i = 0; i < EDGE_MAX; i++)
		if (edge[i] != NULL)
			out << '\t' << edge[i]->get_value() << endl;
}
