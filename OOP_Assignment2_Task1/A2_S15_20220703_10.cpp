// File: A2_S15_20220703_10.cpp
// Purpose: .........
// Author: Omar Salah
// Section: S15
// ID: 20220703
// TA: ........................
// Date: 4 nov 2023
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
string censor(string& originalmessage);
void Problem10()
{
    cout<<"please enter your message to censor"<<endl;
    string s;
    getline(cin,s);
    s=censor(s);
    cout<<s;
}
string censor(string& originalmessage)
{
vector<string> censoredterms;
vector<string> replacements;
string finale;
string censors;
string replacementTerm;
string fixed;
bool replace;
cout<<"Please Enter FilePath for censored terms"<<endl;
string filepath;
getline(cin,filepath);
ifstream file1(filepath);
if (!file1) {
        cout << "Error opening CensoredTerms.txt" << endl;
        return "";
    }
string Line;
while(getline(file1,Line))
{
censoredterms.push_back(Line);
}
cout<<"Please Enter FilePath for terms to replace with"<<endl;
string filepath2;
getline(cin,filepath2);
ifstream file2(filepath2);
if (!file2) {
        cout << "Error opening" << endl;
        return "";
    }
while(getline(file2,Line))
{
replacements.push_back(Line);
}
int random;
string stor;
bool flag;
for (int i=0;i<originalmessage.size();i++)
{
    for (int j=0;j<censoredterms.size();j++)
    {
        if(originalmessage[i]==censoredterms[j][0])
        {
            for (int k=0;k<censoredterms[j].size();k++)
            {
                stor+=originalmessage[i+k];
            }
            if(stor==censoredterms[j])
            {
                random=rand()%replacements.size();
                finale+=replacements[random]+" ";
                i+=censoredterms[j].size();
                stor="";
                flag=true;
            }
        }
    }
if(flag==false)
{
finale+=originalmessage[i];
}
flag=false;

    
}
return finale;
}
void Problem10();