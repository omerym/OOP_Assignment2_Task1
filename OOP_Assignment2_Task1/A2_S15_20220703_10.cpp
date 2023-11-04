#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
string censor(string& originalmessage);
int main()
{
    string s;
    cin>>s;
    s=censor(s);
    cout<<s;
}
string censor(string& originalmessage)
{
string line;
vector<string> censoredterms;
vector<string> replacements;
ifstream file1("TermsToReplace.txt");
string output;
string slice;
string finale;
while(getline(file1,line))
{
censoredterms.push_back(line);
}
ifstream file2("CensoredTerms.txt");
while(getline(file2,line))
{
replacements.push_back(line);
}
for (int i =0;i<originalmessage.size();i++)
{
    for(int j=0;j<censoredterms.size();j++)
    {
        if(originalmessage[i]==censoredterms[j][0])
        {
            for(int k=0;k< censoredterms[j].size();k++)
            {
                slice+=originalmessage[i+k];
            }
            if(slice==censoredterms[j])
            {
                finale+=replacements[j];
            }
            slice.clear();
        }
    }
    finale+=originalmessage[i];
}
return finale;
}