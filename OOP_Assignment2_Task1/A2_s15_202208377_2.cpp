#include <iostream>
#include <string>
using namespace std;
int main() {
    string sentence;
    
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    
   int founded = sentence.find("he");
    while (founded != string::npos) {
        sentence.replace(founded, 3,"he or she");
        founded = sentence.find("he", founded+8); 
    }

    founded = sentence.find("him");
    while (founded != string::npos) {
        sentence.replace(founded,  4,"him or her");
        founded = sentence.find("him", founded+10); 
    }

    founded = sentence.find("his");
    while (founded != string::npos) {
        sentence.replace(founded,  4,"his or her");
        founded = sentence.find("his", founded +10); 
    }

    
   cout << "new sentence: " << sentence << endl;

    return 0;
}