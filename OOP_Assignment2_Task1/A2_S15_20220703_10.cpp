#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
string censor(string& originalmessage);
void Problem10()
{
    string s;
    getline(cin,s);
    s=censor(s);
    cout<<s;
}
string censor(string& originalmessage)
{
string line;
vector<string> censoredterms;
vector<string> replacements;
string output;
string slice;
string finale;
string word;
string censors;
string replacementTerm;
bool replace;
ifstream file1("CensoredTerms.txt");
if (!file1) {
        cout << "Error opening CensoredTerms.txt" << endl;
        return "";
    }
while(file1>>censors)
{
censoredterms.push_back(censors);
}
ifstream file2("TermsToReplace.txt");
if (!file2) {
        cout << "Error opening TermsToReplace.txt" << endl;
        return "";
    }
while(file2>>censors)
{
replacements.push_back(censors);
}
istringstream iss(originalmessage);
while (iss >> word) 
    {
        replace=false;
        for(int i=0;i<censoredterms.size();i++)
    {
        cout<<word<<' '<<censoredterms[i];
        if(word==censoredterms[i])
        {
            finale+=replacements[i]+" ";
            replace=true;
            break;
        }
    }
    if(!replace)
        {
            finale+=word+"";
        }
    }
return finale;
}
void Problem10();