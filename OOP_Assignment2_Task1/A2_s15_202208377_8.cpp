// File: A2_S15_20220837_2cpp
// Purpose: .........
// Author: bashar abdalla
// Section: S15
// ID: 20220837
// TA: ........................
// Date: 4 nov 2023


#ifndef _8
#define _8

#include <iostream>
using namespace std;

void pattern(int length,  int left)
{
   if ( length == 0 ) return;

   pattern(length / 2, left);                            // "Half pattern" above

   for ( int i = 0; i < left  ; i++ ) cout << "  ";
   for ( int i = 0; i < length; i++ ) cout << "* ";        // Central string
   cout << endl;

   pattern(length / 2, left + length / 2);               // "Half pattern" below
}

int main()
{
    cout<<"enter the numbers";
   int n, i;
   cin >> n >> i;
   pattern(n , i);
}
#endif 