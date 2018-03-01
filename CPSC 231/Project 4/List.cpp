#include "List.h"

//Constructor
template <class T>
list<T>::list()
{
	head = NULL;
}


//Destructor - deallocate memory
template <class T>
list<T>::~list()
{
	if (head != NULL)
		delete head;
}

//Queue: Adds to end | Stack: Adds to top
template <class T>
void list<T>::push(T data)
{
	node<T> *p = new node<T>;
	p->data = data;

	if (action == "Queue") 
	{	//add to end
		if (head == NULL)
			head = p;
		else
		{
			node<T> *q = head;
			while (q->next != NULL)
				q = q->next;
			q->next = p;
		}
	}
	else
	{	//add to start
		p->next = head;
		head = p;
	}
}

//Removes and returns first/top data value
template <class T>
T list<T>::pop()
{
	if (head == NULL) return T{}; //not sure what exactly to return. Returning null and forcing the user to not make stupid mistakes sounds better than this, if they get a nullptr exception that's not really this code's fault
	node<T> *p = head;
	T data = p->data;
	head = p->next;
	p->next = NULL;
	delete p; //deallocate original head

	return data;
}

//Change list type (queue vs stack)
template <class T>
void list<T>::method(string action)
{
	this->action = action;
}

template <class T>
bool list<T>::find(T data)
{
	node<T> *p = head;
	while (p != NULL)
		if (p->data == data)
			return true;
		else p = p->next;

	return false;
}

//Number of elements stored
template <class T>
int list<T>::size()
{
	int count = 0;
	node<T> *p = head;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}

	return count;
}