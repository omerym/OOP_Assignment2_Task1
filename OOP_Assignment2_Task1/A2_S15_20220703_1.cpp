#include <iostream>
#include <string>
using namespace std;
void fixer(string& input);
void fixer(string& input){
    string fixed;
int trigger=0;
if('a'<=input[0]&&input[0]<='z')
    {
        fixed+=char(input[0]-32);
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
//the Answer to life, the Universe, and everything IS 42.