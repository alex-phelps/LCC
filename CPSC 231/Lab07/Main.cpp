/*********************************
 * Lab07
 * Created by Alex Phelps
 *********************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*********************************
 * main()
 *********************************/
void main()
{ string s;
  int i;
  fstream infile;
  vector<string> a;
  queue<string> b;
  stack<string> c;

// Open file

  cout << "Enter file name: ";
  cin >> s;
  cout << endl;
  infile.open(s,ios::in);
  if(!infile.is_open()) return;

// Read data from file

  cout << "Input:  ";

  while (!infile.eof())
  {
	  infile >> s;
	  if (infile.good())
	  {
		  cout << s << " ";
		  a.push_back(s);
	  }
  }

  cout << endl;

// Close file

  infile.close();

// Display vector
  cout << "Vector: ";
  for (i = 0; i < a.size(); i++)
	  cout << a[i] << " ";
  cout << endl;

// Copy vector data
  for (i = 0; i < a.size(); i++)
  {
	  if ((i + 1) % 3 == 0)
		  c.push(a[i]);
	  else b.push(a[i]);
  }

// Display queue
  cout << "Queue:  ";
  while (!b.empty())
  {
	  cout << b.front() << " ";
	  b.pop();
  }

  cout << endl;

// Display stack
  cout << "Stack:  ";
  while (!c.empty())
  {
	  cout << c.top() << " ";
	  c.pop();
  }

  cout << endl;
}
