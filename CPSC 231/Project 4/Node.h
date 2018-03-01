#pragma once
#include <string>

using namespace std;

template <class T>
class list;

template <class T>
class node
{ 
  friend class list<T>;

  public:
    node();                           // Null constructor
    ~node();                          // Destructor
  private:
	T data;
    node<T> *next;
};