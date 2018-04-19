/************************************
 * Lab15.cpp
 * Written by YOUR NAME GOES HERE
 ************************************/
#include <iostream>
#include <string>
using namespace std;

#include "Lab15.h2"

/******************************
 * main()
 ******************************/
void main()
{ 
	int i, start, stop, pos, total, temp;
	// Show cities
	cout << "---City List---" << endl;
	for(i = 0; i < CITY_MAX; i++)
		cout << i << ") " << city[i] << endl;

	cout << endl << endl;
	
	cout << "Enter start: ";
	cin >> start;
	cout << "Enter stop: ";
	cin >> stop;

	total = 0;
	pos = start;
	while (pos != stop && pos < CITY_MAX)
	{
		for (temp = 0; temp < CITY_MAX && map[pos][temp] == 0; temp++); // Find first non 0

		if (temp < CITY_MAX)
		{
			cout << city[pos] << " to " << city[temp] << ": " << map[pos][temp] << endl;
			total += map[pos][temp];
			map[pos][temp] = 0;

			for (i = 0; i < CITY_MAX; i++)
				map[i][pos] = 0;
		}

		pos = temp;
	}

	if (pos == stop)
		cout << endl << "Total: " << total << endl;
	else 
		cout << "Could not get there!" << endl;
}
