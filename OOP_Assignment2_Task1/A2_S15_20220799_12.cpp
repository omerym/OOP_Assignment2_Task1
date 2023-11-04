// File: A2_S15_20220799_12cpp
// Purpose: .........
// Author: Omer Yassir
// Section: S15
// ID: 20220799
// TA: ........................
// Date: 1 Nov 2023
#ifndef _12
#define _12

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

void readFile(ifstream& stream, string message = "Enter file name: ");
void readWordFile(unordered_map<string, int>& map);
int evaluateFile(ifstream& in, unordered_map<string, int> map);
string& toLower(string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 'a' - 'A';
		}
	}
	return str;
}

void problem12()
{
	ifstream inputFile;
	unordered_map<string, int> map;
	readWordFile(map);
	readFile(inputFile);
	int score = evaluateFile(inputFile, map);
	cout << score;
}
int evaluateFile(ifstream& in, const unordered_map<string,int> map)
{
	int score = 0;
	string word;
	while (in >> word)
	{
		auto it = map.find(toLower(word));
		if (it != map.end())
		{
			score += it->second;
		}
	}
	return score;
}
void readFile(ifstream& stream,string message)
{
	string fileName;
	cout << message;
	cin >> fileName;
	stream.open(fileName);
	if (!stream.is_open())
	{
		readFile(stream, message);
	}
}
void readWordFile(unordered_map<string, int>  &map)
{
	string wordFileName = "words.txt";
	ifstream in;
	readFile(in, "Enter words file name: ");
	string word;
	int score;
	while (in >> word >> score)
	{
		map[toLower(word)] = score;
	}
}
#endif // !_12
