/*********************************
 * Lab 03
 * Created by Alex Phelps
 *********************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//Sort arrays
void sort(string *names, int *counts, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
			if (counts[j] > counts[j + 1] || (counts[j] == counts[j + 1] && names[j] > names[j + 1]))
			{
				swap(counts[j], counts[j + 1]);
				swap(names[j], names[j + 1]);
			}
}

/*************************************
 * main()
 *************************************/
void main()
{ 
	int n,count;
	fstream infile;
	string fname;

	string *names;
	int *counts;

	// Open file

	cout << "Enter file name: ";
	cin >> fname;
	infile.open(fname.data(),ios::in);

	// Get number of lines

	infile >> n;
	cout << n << " lines in file" << endl << endl;

	names = new string[n];
	counts = new int[n];

	// Loop through file

	count = 0;
	while(!infile.eof())
	{ 
		infile >> names[count] >> counts[count];
		count++;
	};

	// Close file

	infile.close();

	sort(names, counts, n);

	//Output
	for (int i = 0; i < n; i++)
	{
		cout << counts[i] << " " << names[i] << endl;
	}
}
