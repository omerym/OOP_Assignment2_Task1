// File: A2_S15_20220837_5cpp
// Purpose: .........
// Author: bashar abdalla
// Section: S15
// ID: 20220837
// TA: ........................
// Date: 4 nov 2023



#ifndef _2
#define _2


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std; 

struct Player {
    string name;
    int score;
};

void printTopPlayers(const vector<Player>& players) {
    cout << "Top 10 Players and Scores:" << endl;
    vector<Player> sortedPlayers = players;
    sort(sortedPlayers.begin(), sortedPlayers.end(), [](const Player& a, const Player& b) {
        return a.score > b.score;
    });

    int count = 0;
    for (const Player& player : sortedPlayers) {
        cout << player.name << " " << player.score << endl;
        if (++count >= 10) {
            break;
        }
    }
}

int main() {
    vector<Player> players;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a new player and score\n";
        cout << "2. Print the top 10 players and scores\n";
        cout << "3. Enter a player name to get the highest score\n";
        cout << "4.  done\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice." << endl;
            continue;
        }

        if (choice == 1) {
            Player player;
            cout << "Enter player name: ";
            cin >> player.name;
            cout << "Enter player score: ";
            cin >> player.score;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid score." << endl;
                continue;
            }

            players.push_back(player);

            if (players.size() > 10) {
                players.erase(min_element(players.begin(), players.end(),
                    [](const Player& a, const Player& b) { return a.score < b.score; }));
            }
        } else if (choice == 2) {
            printTopPlayers(players);
        } else if (choice == 3) {
            string playerName;
            cout << "Enter player name: ";
            cin >> playerName;
            bool found = false;
            int highestScore = 0;
            for (const Player& player : players) {
                if (player.name == playerName) {
                    found = true;
                    highestScore = max(highestScore, player.score);
                }
            }
            if (found) {
                cout << playerName << "'s highest score is: " << highestScore << endl;
            } else {
                cout << "Player not found in the top 10 list." << endl;
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
#endif 