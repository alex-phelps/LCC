#include "List.h"
#include <string>
#include <iostream>

list::list()
{
	head = NULL;
}

list::~list()
{
	delete head;
}

void list::insert(string first, string last, int age)
{
	node *p = new node;
	p->first = first;
	p->last = last;
	p->age = age;

	if (head == NULL)
		head = p;
	else if (*p < *head)
	{
		p->next = head;
		head = p;
	}
	else
	{
		node *q = head;
		node *r = NULL;
		while (q != NULL && *q < *p)
		{
			r = q;
			q = q->next;
		}

		p->next = q;
		if (r != NULL) r->next = p;
	}
} 

node* list::find(string first, string last)
{
	node* p = head;
	while (p != NULL)
		if (p->first == first && p->last == last) return p;
		else p = p->next;

	return NULL;
}

int list::findall(string first, string last, node** map, int size)
{
	int i = 0;
	node* p = head;
	while (p != NULL && i < size)
	{
		if (p->first == first && p->last == last)
		{
			map[i] = p;
			i++;
		}
		p = p->next;
	}

	return i;
}

bool list::remove(string first, string last)
{
	node *p, *q = head;
	if (head == NULL) return false;
	else while (q != NULL)
	{
		if (q->first == first && q->last == last)
		{
			if (p != NULL) p->next = q->next;
			else head = q->next; //if p = null q is still head

			q->next = NULL;
			delete q;
			return true;
		}
		p = q;
		q = q->next;
	}

	return false;
}

void list::forwards(ostream &out)
{
	head->fore(out);
}

void list::backwards(ostream &out)
{
	head->back(out);
}

int list::length()
{
	if (head == NULL) return 0;

	node *p = head;
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}