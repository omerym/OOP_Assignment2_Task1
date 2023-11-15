#include <iostream>
#include <vector>
#include <string>
#include <cctype> 

using namespace std;

int problem2() {
    vector<string> strs;
    string str;

    // take input as line
    getline(cin, str);

    char separator = ' ';

    // store every string chars in copy string
    string copy;
    
    for (int i = 0; i < str.size(); i++) {
        // if char in str is " " then push back to vector as one string and clear it
        if (str[i] == separator) {
            strs.push_back(copy);
            copy.clear();
        }
        // other wise will keep add char to string copy
         else {
            copy += str[i];
        }
    }

    // Push the last word into the vector (it may not end with a space)
    strs.push_back(copy);

    for (int i = 0; i < strs.size(); i++) {

        // store current string size in curStrSize
        int curStrSize = strs[i].size();

        //  store string in the another string
        string another = strs[i];

        // to store last char in current string
        char lastChar = another[another.size() - 1];

        // delete last char in string another in case if the string was (him! or him? or him5) 
        another.pop_back();

        // first check if the string equal if "Him" or "him" if don't equal then if the string without last char ('.' or '?' or '5') if equal if will replace it other wise will continue wit doing anything
        if (strs[i] == "Him" || strs[i] == "him" || (!isdigit(strs[i][curStrSize - 1]) && (another == "Him" || another == "him"))) {
            if (strs[i] == "Him") {
                strs[i] = "Him or her";
            } else if (strs[i] == "him") {
                strs[i] = "him or her";
            } else {
                strs[i] = "him or her";
                strs[i].push_back(lastChar);
            }
        } else if (strs[i] == "He" || strs[i] == "he" || (!isdigit(strs[i][curStrSize - 1]) && (strs[i] == "He" || strs[i] == "he"))) {
            if (strs[i] == "He") {
                strs[i] = "He or she";
            } else if (strs[i] == "he") {
                strs[i] = "he or she";
            } else {
                strs[i] = "he or she";
            }
        }
    }

    for (int i = 0; i < strs.size(); i++) {
        cout << strs[i] << " ";
    }

    return 0;
}