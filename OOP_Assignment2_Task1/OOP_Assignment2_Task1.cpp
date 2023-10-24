// OOP_Assignment2_Task1.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "A2_S15_20220799_3.cpp"

using namespace std;

int main()
{
	cout << "enter problem number: ";
	int pn;
	cin >> pn;
	switch (pn)
	{
	case 3:
		problem3();
	default:
		cout << "!!!!!!!!!";
		break;
	}
	return 0;
}
