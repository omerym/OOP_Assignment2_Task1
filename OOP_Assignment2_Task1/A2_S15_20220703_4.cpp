#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Primes(int N)
{
vector<int> storage;
for(int i=0;i<N;i++)
{
    storage.push_back(i);
}
for (int i =2;i<N;i++)
{
    for(int j=i;j<N;j++)
    {
        if(j*i<N)
        {
            storage[j*i]=0;
        }
    }
}
for(int i=0;i<N;i++)
{
    if(storage[i]!=0)
    {
        cout<<storage[i]<<endl;
    }
}
}
void Problem4();
void Problem4()
{
    int N;
    cout<<"enter number to get primes below";
    cin>>N;
    Primes(N);
}