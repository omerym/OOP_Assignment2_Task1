// OOP_Assignment2_Task1.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "A2_S15_20220703_1.cpp"
#include "A2_S15_20220799_3.cpp"
#include "A2_S15_20220703_4.cpp"
#include "A2_S15_20220799_6.cpp"
#include "A2_S15_20220703_7.cpp"
#include "A2_S15_20220799_9.cpp"
#include "A2_S15_20220703_10.cpp"
#include "A2_s15_202208377_2.cpp"
#include "A2_s15_202208377_8.cpp"
#include "A2_S15_20220799_12.cpp"
void Problem1();
using namespace std;

int main()
{
	cout << "enter problem number:";
	int pn;
	cin >> pn;
	cin.ignore();
	switch (pn)
	{
	case 1:
		Problem1();
		break;
	case 2:
		break;
	case 3:
		problem3();
		break;
	case 4:
		Problem4();
		break;
	case 6:
		problem6();
	case 7:
		Problem7();
		break;
	case 9:
		problem9();
		break;
	case 10:
		Problem10();
		break;
	case 11:
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
