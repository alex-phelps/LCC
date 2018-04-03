/************************************
 * Heapsort.cpp
 * Written by Alex Phelps
 ************************************/

#include "Heapsort.h"

//Returns left child position
inline int heap_left(int pos)
{
	return pos * 2 + 1;
}

//Returns right child position
inline int heap_right(int pos)
{
	return pos * 2 + 2;
}

//Returns parent position
inline int heap_parent(int pos)
{
	return (pos - 1) / 2;
}

//Inserts a value into the heap
void heap_insert(string map[], int &n, string value)
{
	map[n] = value;
	int pos = n;
	int parent = heap_parent(pos);

	while (pos > 0 && map[pos] > map[parent])
	{
		swap(map[pos], map[parent]);
		pos = parent;
		parent = heap_parent(pos);
	}

	n++;
}

//Removes top value from the heap
void heap_remove(string map[], int &n, string &value)
{
	int index, left, right, pos = 0;
	n--;
	swap(map[0], map[n]);

	while (pos < n)
	{
		index = pos;
		left = heap_left(pos);
		right = heap_right(pos);

		if (left < n && map[left] > map[index])
			index = left;
		if (right < n && map[right] > map[index])
			index = right;

		if (pos != index)
		{
			swap(map[pos], map[index]);
			pos = index;
		}
		else pos = n;
	}

	value = map[n];
}

//Converts array into heap
void heapify(string map[], int n)
{
	int i = 0;

	while (i < n)
		heap_insert(map, i, map[i]);
}

//Sorts heap
void heap_sort(string map[], int n)
{
	string temp;

	while (n > 0)
		heap_remove(map, n, temp);
}