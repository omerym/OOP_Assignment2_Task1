#ifndef _3
#define _3

#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> split(string target, string delimiter);
void getWords(vector<string>& r, string target, const string& delimiter);

void problem3()
{
	string s, d;
	getline(cin, s);
	getline(cin, d);
	vector<string> v = split(s, d);
	for (auto &x : v)
	{
		cout << x << endl;
	}
}
void getWords(vector<string> &r, string target, const string &delimiter)
{
	int idx = target.find(delimiter);
	if (idx == string::npos)
	{
		r.push_back(target);
		return;
	}
	r.push_back(target.substr(0, idx));
	getWords(r, target.substr(idx + delimiter.length()), delimiter);
}

vector<string> split(string target, string delimiter)
{
	vector<string> r = vector<string>();
	getWords(r, target, delimiter);
	return r;
}
#endif // !_3
