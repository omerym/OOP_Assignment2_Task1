// File: A2_S15_20220703_1.cpp
// Purpose: .........
// Author: Omar Salah
// Section: S15
// ID: 20220703
// TA: ........................
// Date: 4 nov 2023
#include <iostream>
#include <string>
using namespace std;
void fixer(string& input){
    string fixed;
int trigger=0;
if('a'<=input[0]&&input[0]<='z')
    {
        fixed+=char(input[0]-32);
    }
else
{
    fixed+=input[0];
}
for(int i=1;i<input.size();i++){
    if(input[i]==' ')
    {
        if(trigger==0)
        {
            trigger=1;
            fixed+=input[i];
        }
        else
        {
            
        }
    }
    else
    {
        trigger=0;
        if('A'<=input[i]&&input[i]<='Z')
        {
            fixed+=char(input[i]+32);
        }
        else
        {
            fixed+=input[i];
        }
    }
}
input = fixed;
}
void Problem1()
{
    cout<<"Please enter string to fix: "<<endl;
    string S;
    getline(cin,S);
    fixer(S);
    cout<<S;
}