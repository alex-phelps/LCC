#pragma once
#include "Node.cpp"
#include <string>

using namespace std;

template <class T>
class list
{
public:
	list(); //Constructor
	~list(); //Destructor
	void push(T); //Adds a value
	T pop(); //Removes and returns top value
	void method(string); //Changes between stack/queue
	bool find(T); //True if value exists in list - Note: == operator must be overloaded
	int size(); //number of elements in list

private:
	node<T>* head;
	string action;
};