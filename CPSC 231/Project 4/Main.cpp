/***********************************
 * Program 04
 * Written by Mark M Bowman
 ***********************************/ 

#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "List.cpp"
#include "Box.h"
#include "Bushel.h"

void test_int(string);
void test_float(string);
void test_string(string);
void test_box(string);
void test_bushel(string);

/***********************************
 * Main
 ***********************************/ 
void main()
{ 

// Int stack and queue

  cout << "Integer Queue\n----------------\n";
  test_int("Queue");
  cout << endl;

  cout << "Integer Stack\n----------------\n";
  test_int("Stack");
  cout << endl;

// Float stack and queue

  cout << "Float Queue\n----------------\n";
  test_float("Queue");
  cout << endl;

  cout << "Float Stack\n----------------\n";
  test_float("Stack");
  cout << endl;

// String stack and queue

  cout << "String Queue\n----------------\n";
  test_string("Queue");
  cout << endl;

  cout << "String Stack\n----------------\n";
  test_string("Stack");
  cout << endl;

// Box stack and queue

  cout << "Box Queue\n----------------\n";
  test_box("Queue");
  cout << endl;

  cout << "Box Stack\n----------------\n";
  test_box("Stack");
  cout << endl;

// Bushel stack and queue

  cout << "Bushel Queue\n----------------\n";
  test_bushel("Queue");
  cout << endl;

  cout << "Bushel Stack\n----------------\n";
  test_bushel("Stack");
  cout << endl;
}

/***********************************
 * test_int()
 ***********************************/ 
void test_int(string action)
{ int i;
  list<int> a;

// Set method

  a.method(action);

// Push onto list

  for(i=0;i<25;i++) a.push(i);

  //Find
  cout << "Find: "<< a.find(4) << endl;

// Pop off stack

  while(a.size()>0)
    cout << a.pop() << " ";
  cout << endl;
}

/***********************************
 * test_float()
 ***********************************/ 
void test_float(string action)
{ int i;
  list<float> a;

// Set method

  a.method(action);

// Push onto list

  for(i=0;i<5;i++) a.push(sqrt((float)i));

  //Find
  cout << "Find: "<< a.find(3.4f) << endl;

// Pop off stack

  cout << fixed << setprecision(4);
  while(a.size()>0)
    cout << a.pop() << endl;
}

/***********************************
 * test_string()
 ***********************************/ 
void test_string(string action)
{ int i;
  string val[7] = { "Richard","David","Mark","Frank","Susan","Kathy","John" };
  list<string> a;

// Set method

  a.method(action);

// Push onto list

  for(i=0;i<7;i++) a.push(val[i]);

  //Find
  cout << "Find: "<< a.find("Mark") << endl;

// Pop off stack

  while(a.size()>0)
    cout << a.pop() << endl;
}

/***********************************
 * test_box()
 ***********************************/ 
void test_box(string action)
{ int i;
  box temp,val[3] = { box(3,5), box(4,6), box(2,4) };
  list<box> a;

// Set method

  a.method(action);

// Push onto list

  for(i=0;i<3;i++) a.push(val[i]);

  //Find
  cout << "Find: "<< a.find(box(3, 5)) << endl;

// Pop off stack

  while(a.size()>0)
    { temp = a.pop();
      temp.put(cout);
      cout << endl;
    };

// Force Underflow

  temp = a.pop();
  temp.put(cout);
  cout << endl;
}

/***********************************
 * test_bushel()
 ***********************************/ 
void test_bushel(string action)
{ int i;
  bushel temp,val[4] = { bushel(3,5), bushel(4,6), bushel(2,4), bushel(10,10) };
  list<bushel> a;

// Set method

  a.method(action);

// Push onto list

  for(i=0;i<4;i++) a.push(val[i]);

  //Find
  cout << "Find: "<< a.find(bushel(0, 1)) << endl;

// Pop off stack

  while(a.size()>0)
    { temp = a.pop();
      temp.put(cout);
      cout << endl;
    };
}
