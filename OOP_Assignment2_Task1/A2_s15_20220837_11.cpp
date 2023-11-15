#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void characterCompare(ifstream& file1, ifstream& file2) {

    string line1;
    string line2;
    int lineNumber = 1;
    while (getline(file1, line1) && getline(file2, line2)) {

        if (line1 != line2) {
            cout << "Line Number: " << lineNumber << '\n';
            cout << "the different line is: ";
            cout << line1 << '\n';
            cout << "the different line is: ";
            cout << line2;

            return;
        }
        lineNumber++;
    }
    
    cout << "the two files are identical";

}


void wordCompare(ifstream& file1, ifstream& file2) {
    vector<vector<string>> v1;
    vector<vector<string>> v2;
    string line1;
    string line2;
    int lineNumber = 1;

    while (getline(file1, line1) && getline(file2, line2)) {
        vector<string> words1;
        vector<string> words2;

        
        stringstream ss1(line1);
        string word;
        while (ss1 >> word) {
            words1.push_back(word);
        }

        stringstream ss2(line2);
        while (ss2 >> word) {
            words2.push_back(word);
        }

        v1.push_back(words1);
        v2.push_back(words2);

        lineNumber++;
    }

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        int ch = 0;
        while (ch < v1[i].size() && ch < v2[j].size()) {

            if (v1[i][ch] != v2[j][ch]) {

                cout << "First different word: " << v2[i][ch] << '\n';

                cout << "File 1: ";
                for (int word = 0; word < v1.size(); word++) {
                    cout << v1[i][word] << " ";
                }

                cout << '\n';

                cout << "File 2: ";
                for (int word = 0; word < v2.size(); word++) {
                    cout << v2[i][word] << " ";
                }
                return;
            }
            ch++;
        }
        i++;
        j++;
    }

    cout << "The files are identical";
}





void problem11() {

    vector <vector<string>> diff;

    string path1;
    string path2;
    ifstream file1;
    ifstream file2;

    cout << "Enter file1 path: ";
    cin >> path1; 
    cout << '\n' << "Enter file2 path : ";
    cin >> path2;

    path1.append(".txt");
    path2.append(".txt");

    file1.open(path1);
    file2.open(path2);




    char option;
    cout << "C : to compare two files by characters \n";
    cout << "W : to compare two files by words \n";

    cin >> option;



    if (option == 'C' || option == 'c') {
        characterCompare(file1, file2);
    }
    else if (option == 'W' || option == 'w') {
        wordCompare(file1, file2);
    }


    file1.close();
    file2.close();

}