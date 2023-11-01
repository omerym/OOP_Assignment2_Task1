#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool compareByCharacter(const string &file1, const string &file2) {
    ifstream f1(file1), f2(file2);
    char c1, c2;
    int line = 1, stringS = 1;

    while (f1.get(c1) && f2.get(c2)) {
        if (c1 != c2) {
            cout << "Files are different at line " << line << ", character " << stringS << endl;
            cout << "File 1: " << c1 << endl;
            cout << "File 2: " << c2 << endl;
            return false;
        }
        if (c1 == '\n') {
            line++;
           stringS = 0;
        }

        stringS++;
    }

    if (!f1.eof() || !f2.eof()) {
        cout << "Files have different lengths." << endl;
        return false;
    }

    cout << "Files are identical." << endl;
    return true;
}

// Function to compare files  by word
bool compareByWord(const string &file1, const string &file2) {
    ifstream f1(file1), f2(file2);
    string word1, word2;
    int line = 1;

    while (f1 >> word1 && f2 >> word2) {
        if (word1 != word2) {
            cout << "Files are different at line " << line << endl;
            cout << "File 1: " << word1 << endl;
            cout << "File 2: " << word2 << endl;
            return false;
        }

        if (word1.find('\n') != string::npos) {
            line++;
        }
    }

    if ((!f1.eof() && f2.eof()) || (f1.eof() && !f2.eof())) {
        cout << "Files have different lengths." << endl;
        return false;
    }

    cout << "Files are identical." << endl;
    return true;
}

int main() {
    string file1, file2;
    int choice;

    cout << "Enter the name of the first file: ";
    cin >> file1;
    cout << "Enter the name of the second file: ";
    cin >> file2;

    cout << "Choose comparison type:" << endl;
    cout << "1. Character by character" << endl;
    cout << "2. Word by word" << endl;
    cin >> choice;

    if (choice == 1) {
        compareByCharacter(file1, file2);
    } else if (choice == 2) {
        compareByWord(file1, file2);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}