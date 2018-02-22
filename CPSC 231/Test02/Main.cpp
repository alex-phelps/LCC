/*********************************
 * Test 02
 * Created by Alex Phelps
 *********************************/
#include <iostream>
#include <string>
using namespace std;

template <class T>
T minimum(T map[], int size)
{
	int i;
	T *min = NULL;

	for (i = 0; i < size; i++)
	{
		if (min == NULL || map[i] < *min)
			min = &map[i];
	}

	return *min;
}

template <class T>
T maximum(T map[], int size)
{
	int i;
	T *max = NULL;

	for (i = 0; i < size; i++)
	{
		if (max == NULL || map[i] > *max)
			max = &map[i];
	}

	return *max;
}

/*************************************
 * main()
 *************************************/
void main()
{ int imap[10] = { 5,1,7,8,6,7,5,3,0,9 };
  float fmap[5] = { 3.14F,2.13F,6.02F,9.87F,1.46F };
  string smap[7] = { "Richard","David","Mark","Frank","Suzanne","Kathy","John" };

// Display minimums

  cout << "Minimums: ";
  cout << minimum(imap,10) << ", ";
  cout << minimum(fmap,5) << ", ";
  cout << minimum(smap,7) << endl;

// Display maximums

  cout << "Maximums: ";
  cout << maximum(imap,10) << ", ";
  cout << maximum(fmap,5) << ", ";
  cout << maximum(smap,7) << endl;
}
