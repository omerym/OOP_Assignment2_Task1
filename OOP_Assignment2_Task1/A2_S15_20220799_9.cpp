// File: A2_S15_20220799_9cpp
// Purpose: .........
// Author: Omer Yassir
// Section: S15
// ID: 20220799
// TA: ........................
// Date: 24 Oct 2023
#ifndef _9
#define _9

#include <iostream>

using namespace std;
bool bear(int bears);
void problem9()
{
	cout << "Enter number of bears:";
	int bears;
	cin >> bears;
	bool r = bear(bears);
	cout << (r ? "true" : "false");
}

bool bear(int bears)
{
	if (bears < 42)
	{
		return false;
	}
	if (bears == 42)
	{
		return true;
	}
	if (bears % 2 == 0)
	{
		if (bears / 2)
		{
			return true;
		}
	}
	if (bears % 3 == 0 || bears % 4 == 0)
	{
		int d1 = bears % 10;
		int d2 = (bears / 10) % 10;
		if (bear(bears - d1 * d2))
		{
			return true;
		}
	}
	if (bears % 5 == 0)
	{
		if (bear(bears - 42))
		{
			return true;
		}
	}
	return false;
}
#endif // !_9
