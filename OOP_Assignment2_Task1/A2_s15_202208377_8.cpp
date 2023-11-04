// File: A2_S15_20220837_8cpp
// Purpose: .........
// Author: bashar abdalla
// Section: S15
// ID: 20220837
// TA: ........................
// Date: 4 nov 2023


#ifndef _2
#define _2


#include <iostream>
using namespace std;
void fractal(int n) {
    for (int i = 0; i < n; i++) {
        cout << "* ";
    }
    cout << endl;
}

void pattern(int n, int i) {
    if (n == 1) {
        fractal(1); 
    } else {
        pattern(n / 2, i+1); 
        fractal(n); 
        pattern(n / 2, i + n); 
    }
}

int main() {
    pattern(8, 0); 
    return 0;
}
#endif 