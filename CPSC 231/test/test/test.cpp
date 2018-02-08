#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int mainv()
{
	int *arr = new int[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	arr[4] = -1;

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}