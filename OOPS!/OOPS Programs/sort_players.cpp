#include <iostream>
#include <cstring>
using namespace std;

// Define the class 'Player'
class Player {
private:
    char name[50];   // Name of the player
    float average;   // Batting average
    int runs;        // Runs scored

public:
    // Function to input player details
    void input() {
        cout << "Enter player's name: ";
        cin.ignore();  // Clear the input buffer
        cin.getline(name, 50);
        cout << "Enter player's batting average: ";
        cin >> average;
        cout << "Enter player's total runs: ";
        cin >> runs;
    }

    // Function to display player details
    void display() const {
        cout << "Name: " << name << ", Average: " << average << ", Runs: " << runs << endl;
    }

    // Getter for runs (used for sorting)
    int getRuns() const {
        return runs;
    }
};

// Function to sort players in descending order of runs
void sortPlayers(Player players[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (players[i].getRuns() < players[j].getRuns()) {
                // Swap the players
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of players: ";
    cin >> n;

    // Declare an array of Player objects
    Player players[n];

    // Input player details
    cout << "\nEnter details for " << n << " players:\n";
    for (int i = 0; i < n; i++) {
        cout << "Player " << i + 1 << ":\n";
        players[i].input();
    }

    // Sort players in descending order of runs
    sortPlayers(players, n);

    // Display sorted player details
    cout << "\nPlayers sorted by runs (descending order):\n";
    for (int i = 0; i < n; i++) {
        players[i].display();
    }

    return 0;
}
