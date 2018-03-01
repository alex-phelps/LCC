/*********************************
 * Lab 11
 * Created by Alex Phelps
 *********************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#define TABLE_MAX  21

#include "Node.h"

int hash_insert(node *table[],node *p,int id);

/*********************************
 * main()
 *********************************/
void main()
{ int i,id,count;
  string fname,first,last;
  fstream infile;
  node *table[TABLE_MAX],*p;

// Initialize

  for(i=0;i<TABLE_MAX;i++)
    table[i] = NULL;
  count = 0;

// Open file

  cout << "Enter file name: ";
  cin >> fname;
  infile.open(fname.data(),ios::in);
  if(!infile.is_open()) return;

// Read data from file

  while(!infile.eof())
  { 
	  infile >> id >> first >> last;

// Process if input is valid

      if(infile.good())
      { 
		  p = new node{ id, first, last };
		  count += hash_insert(table, p, id);
      };
  };

// Close file

  infile.close();

// Display table

  cout << endl;
  for(i=0;i<TABLE_MAX;i++)
    { cout << left << setw(4) << i;
      if(table[i]!=NULL) table[i]->put(cout);
      cout << endl;
    };

// Collisions

  cout << endl;
  cout << "Collisions: " << count << endl;

// Clean up

  for(i=0;i<TABLE_MAX;i++)
    if(table[i]!=NULL) delete table[i];
}

//Inserts node into the hash table
int hash_insert(node *table[], node *p, int id)
{
	int count = 0;
	int index = (id * 215 + 37) % 21;
	int base = index;

	while (table[index] != NULL)
	{
		count++;
		index = (++index) % TABLE_MAX;
		if (index == base) return count; //table is full, no insert
	}

	table[index] = p;
	return count;
}