/******************************************************
 # Lab 12
 # Created by Alex Phelps & Bryce Weldon
 ******************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define ARRAY_MAX  10000

void merge(string map[],int n);
void merge_sort(string map[],int n);

/*************************************
 * main()
 *************************************/
void main()
{ int i,n;
  string map[ARRAY_MAX];
  string fname;
  fstream infile;

// Initialize

  n = 0;

// Open file

  cout << "Enter data file name: ";
  cin >> fname;
  infile.open(fname.data(),ios::in);
  if(!infile.is_open()) return;

// Loop through file

  while(!infile.eof())
    { infile >> map[n];

// Update index if valid input

      if(infile.good()) n++;
    };

// Close file

  infile.close();

// Output map

  merge_sort(map, n);

  cout << endl;
  for(i=0;i<n;i++)
    cout << map[i] << endl;
}

//Merges 2 halves of array
void merge(string map[], int n)
{
	string temp[ARRAY_MAX];

	int i = 0, pos1 = 0, pos2 = n / 2;

	while (pos1 < n / 2 && pos2 < n)
	{
		if (map[pos1] < map[pos2])
		{
			temp[i] = map[pos1];
			pos1++;
		}
		else
		{
			temp[i] = map[pos2];
			pos2++;
		}

		i++;
	}

	while (pos1 < n / 2)
	{
		temp[i] = map[pos1];
		i++;
		pos1++;
	}

	while (pos2 < n)
	{
		temp[i] = map[pos2];
		i++;
		pos2++;
	}

	for (i = 0; i < n; i++)
		map[i] = temp[i];
}

//Sorts array
void merge_sort(string map[], int n)
{
	if (n > 2)
	{
		merge_sort(map, n / 2);
		merge_sort(map + n / 2, n - n / 2);
		merge(map, n);
	}
	else if (n == 2 && map[0] > map[1]) swap(map[0], map[1]);
}