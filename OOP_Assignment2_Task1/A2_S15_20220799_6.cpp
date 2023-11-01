// File: A2_S15_20220799_6cpp
// Purpose: .........
// Author: Omer Yassir
// Section: S15
// ID: 20220799
// TA: ........................
// Date: 24 Oct 2023
#ifndef _6
#define _6

#include <iostream>
#include <string>

using namespace std;
static void binaryPrintNonZero(int n);
static void binaryPrint(int n);
static void numbers(string prefix, int k);
int getDigitCount(int x);
void printNumbers(const string &prefix, int k, int length);
void problem6A(); 
void problem6B();
void problem6()
{
	cout << "Problem a or b?";
	char c;
	cin >> c;
	if (c == 'a' || c == 'A')
	{
		problem6A();
	}
	else
	{
		problem6B();
	}
}
void problem6A()
{
	cout << "Enter a number:";
	int x;
	cin >> x;
	binaryPrint(x);
}
void problem6B()
{
	string prefix;
	int k;
	cout << "Enter prefix:";
	cin >> prefix;
	cout << "Enter k:";
	cin >> k;
	numbers(prefix, k);
}
void binaryPrintNonZero(int n)
{
	if (n == 0)
	{
		return;
	}
	binaryPrintNonZero(n >> 1);
	cout << (n & 1);
}

void binaryPrint(int n)
{
	if (n == 0)
	{
		cout << 0;
	}
	else
	{
		binaryPrintNonZero(n);
	}
}
int getDigitCount(int x)
{
	if (x <= 1)
	{
		return 1;
	}
	return 1 + getDigitCount(x >> 1);
}
void numbers(string prefix, int k)
{
	printNumbers(prefix, (1 << k) - 1, k);
}
void printZeros(int count)
{
	if (count <= 0)
	{
		return;
	}
	cout << 0;
	printZeros(count - 1);
}
void printNumbers(const string &prefix, int suffix, int length)
{
	if (suffix < 0)
	{
		return;
	}
	printNumbers(prefix, suffix - 1, length);
	cout << prefix;
	printZeros(length - getDigitCount(suffix));
	binaryPrint(suffix);
	cout << endl;
}
#endif // !_6
