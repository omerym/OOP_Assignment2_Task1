#include <iostream>
#include <vector>
using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

bool success(vector <dominoT> Dominos,vector<dominoT>& correctDominos, int slot = 0);

void Problem7() {
    vector<dominoT> blocks;
    int numDominoes;
    cout<<"Please enter your Dominoes";
    cin >> numDominoes;

    for (int i = 0; i < numDominoes; i++) {
        dominoT domino;
        cin >> domino.leftDots >> domino.rightDots;
        blocks.push_back(domino);
    }
    vector<dominoT> correctDominos;
    if (success(blocks,correctDominos)) {
        cout << "it works";
    } else {
        cout << "fail";
    }

    for(int i=0;i<correctDominos.size();i++)
    {
        if(i!=correctDominos.size()-1)
        {
            cout<< ' '<<correctDominos[i].leftDots<<' '<<'|'<<' '<<correctDominos[i].rightDots<<' '<<'-';
        }
    }
}
    bool success(vector<dominoT> Dominos, vector<dominoT>& correctDominos, int slot) {
    if (slot == Dominos.size()) {
        return true;
    }

    for (int i = slot; i < Dominos.size(); i++) {
        if (slot == 0 || Dominos[i].leftDots == correctDominos.back().rightDots) {
            correctDominos.push_back(Dominos[i]);

            if (success(Dominos, correctDominos, slot + 1)) {
                return true;
            }

            correctDominos.pop_back();
        }
    }

    return false;
}
void Problem7();
