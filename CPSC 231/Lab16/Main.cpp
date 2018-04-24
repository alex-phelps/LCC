/************************************
 * Lab16.cpp
 * Written by Alex Phelps
 ************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAP_MAX   50
#define DATA_MAX  100
#define ERR       -1

int  data_load(string fname,string data[]);
int  map_display(string map[],int width);

//Adds to map by first fitting string
void map_first(string map[], string data[], int n, int width)
{
	int i, row = 0;

	for (i = 0; i < n; i++)
	{
		if (map[row].length() + data[i].length() > width) row++;
		map[row] += data[i];
	}
}

//Finds largest that will fit in line
int map_largest(string line, string data[], int n, int width)
{
	int i, pos = ERR, size = 0;

	for (i = 0; i < n; i++)
		if (line.length() + data[i].length() <= width && data[i].length() > size)
		{
			pos = i;
			size = data[i].length();
		}

	return pos;
}

//Finds smallest that will fit in line
int map_smallest(string line, string data[], int n, int width)
{
	int i, pos = ERR, size = INT_MAX;

	for (i = 0; i < n; i++)
		if (line.length() + data[i].length() <= width && data[i].length() < size)
		{
			pos = i;
			size = data[i].length();
		}

	return pos;
}

//Adds by selecting largest that will fit
void map_best(string map[], string data[], int n, int width)
{
	int i, pos, row = 0;

	while (n > 0)
	{
		pos = map_largest(map[row], data, n, width);
		if (pos == ERR)
			row++;
		else
		{
			map[row] += data[pos];
			data[pos] = data[n - 1];
			n--;
		}
	}
}

//Adds by selecting smallest that will fit
void map_worst(string map[], string data[], int n, int width)
{
	int i, pos, row = 0;

	while (n > 0)
	{
		pos = map_smallest(map[row], data, n, width);
		if (pos == ERR)
			row++;
		else
		{
			map[row] += data[pos];
			data[pos] = data[n - 1];
			n--;
		}
	}
}

/*******************************
 * main()
 *******************************/
void main()
{ int i,n,width,waste;
  string map[MAP_MAX];
  string data[DATA_MAX];
  string fname,s;

// Initialize map

  for(i=0;i<MAP_MAX;i++) map[i] = "";
  n = 0;

// Get file name and number of columns

  cout << "Enter data file: ";
  cin >> fname;
  cout << "Enter width of map: ";
  cin >> width;
  cout << endl;

// Load data

  n = data_load(fname,data);

// Display data

  //for(i=0;i<n;i++)
  //  cout << data[i] << endl;
  //cout << endl;

// Call First, Best, or Worst fit function
  cout << "Enter method (First,Best,Worst): ";
  cin >> s;

  if (s == "First")
	  map_first(map, data, n, width);
  else if (s == "Best")
	  map_best(map, data, n, width);
  else map_worst(map, data, n, width);

// Display map

  waste = map_display(map,width);
  cout << "Wasted space: " << waste << endl;
}

/*******************************
 * data_load()
 *******************************/
int data_load(string fname,string data[])
{ int n;
  fstream in;

// Initialize

  n = 0;

// Open file

  in.open(fname.data(),ios::in);
  if(!in.is_open()) return 0;

// Loop through file

  while(!in.eof() && n<DATA_MAX)
    { in >> data[n];
      if(in.good()) n++;
    };

// Close file and return count

  in.close();
  return n;
}

/*******************************
 * map_display()
 *******************************/
int map_display(string map[],int width)
{ int i,j,n;

// Initialize

  n = 0;
  for(j=0;j<width;j++) cout << '-';
  cout << endl;

// Loop through rows

  for(i=0;i<MAP_MAX && map[i].length()>0;i++)
    { cout << map[i];
      for(j=map[i].length();j<width;j++)
        cout << '.';
      cout << endl;

// Sum wasted space

      n += width-map[i].length();
    };

// Bottom line

  for(j=0;j<width;j++) cout << '-';
  cout << endl << endl;

// Return wasted space

  return n;
}

