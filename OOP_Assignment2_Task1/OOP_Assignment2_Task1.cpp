// OOP_Assignment2_Task1.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "A2_S15_20220799_3.cpp"
#include "A2_S15_20220799_6.cpp"
#include "A2_S15_20220799_9.cpp"
#include "A2_S15_20220799_12.cpp"

using namespace std;

int main()
{
	cout << "enter problem number:";
	int pn;
	cin >> pn;
	switch (pn)
	{
	case 3:
		problem3();
		break;
	case 6:
		problem6();
		break;
	case 9:
		problem9();
		break;
	case 12:
		problem12();
		break;
	default:
		cout << "!!!!!!!!!";
		break;
	}
	return 0;
}
