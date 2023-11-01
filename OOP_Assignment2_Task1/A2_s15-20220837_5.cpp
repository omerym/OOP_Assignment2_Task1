#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
// Struct to store player data
struct Player {
    string name;
    int score;
};

int main() {
    vector<Player> playerList;
    const int  maxPlayers = 10;

    while (true) {
        cout << "1. Add a new player and score\n";
        cout << "2. Print the top 10 names and scores\n";
        cout << "3. Check a player's highest score\n";
        cout << "4. Exit\n";
        cout << "Enter your decision: ";
        int decision;
        cin >> decision;

        switch (decision) {
            case 1:
                if (playerList.size() >= maxPlayers) {
                    // Remove the player with the lowest score
                    int minScorePlayer = min_element(playerList.begin(), playerList.end(),[]
                        (const Player &a, const Player &b) {
                            return a.score < b.score;
                        });
                    playerList.erase(minScorePlayer);
                };

             // Add a new player and score
                Player newPlayer;
                cout << "Enter the player's name: ";
                cin >> newPlayer.name;
                cout << "Enter the player's score: ";
                cin >> newPlayer.score;
                playerList.push_back(newPlayer);
                break;
       

            case 2:
                // Sort and print the top 10 names and scores
                sort(playerList.rbegin(), playerList.rend(),
                    [](const Player &a, const Player &b) {
                        return a.score < b.score;
                    });

                cout << "Top 10 names and scores:\n";
                for (int i = 0; i < min(maxPlayers, static_cast<int>(playerList.size())); i++) {
                    cout << playerList[i].name << " " << playerList[i].score << endl;
                }
                break;

            case 3:
                // Check a player's highest score
                string playerName;
                cout << "Enter the player's name: ";
                cin >> playerName;

                int highestScore = 0;
                for (const Player &player : playerList) {
                    if (player.name == playerName) {
                        highestScore = max(highestScore, player.score);
                    }
                }

                if (highestScore > 0) {
                   cout << playerName << "'s highest score is: " << highestScore << endl;
                } else {
                    cout << playerName << " is not in the top 10 or hasn't been added." << endl;
                }
                break;

            case 4:
                
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}