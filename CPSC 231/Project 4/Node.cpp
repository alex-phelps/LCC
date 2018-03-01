#include "node.h"

using namespace std;

//Constructor
template <class T>
node<T>::node()
{
	next = NULL;
}

//Destructor - deallocate memory
template <class T>
node<T>::~node()
{
	if (next != NULL)
		delete next;
}