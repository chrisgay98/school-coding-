// PlayersOnTeamStephenson.cpp
// CIS054 – Players on a Team (C++)
// Determines if there are too few, too many, or just enough players.

#include <iostream>
#include <limits>   // for numeric_limits
using namespace std;

int selectTeamSize();           // function prototype
int readInt(const char* prompt);// safe integer input helper

int main() {
    cout << "=== Team Size Selector ===\n\n";

    // 1) Get team size based on sport selection
    int teamSize = selectTeamSize();
    if (teamSize == 0) {
        // user never selected a valid sport (shouldn’t happen with our loop)
        cout << "Exiting.\n";
        return 1;
    }
    cout << "\nA full team has " << teamSize << " players.\n";

    // 2) Get number of players trying out
    int playersOnTeam = readInt("How many players are currently trying to get on the team? ");

    // 3) Decide + report
    if (playersOnTeam < teamSize) {
        int moreNeeded = teamSize - playersOnTeam;
        cout << "There are not enough players. " << moreNeeded
             << " more players are needed.\n";
    } else if (playersOnTeam > teamSize) {
        int extra = playersOnTeam - teamSize;
        cout << "There are too many players, " << extra
             << " players need to be eliminated.\n";
    } else {
        cout << "You have the correct number of players.\n";
    }

    return 0;
}

// ----- functions -----

int selectTeamSize() {
    // Menu loop until a valid selection (1–4)
    while (true) {
        cout << "Select a professional sport:\n"
             << " 1 - NFL Football\n"
             << " 2 - NBA Basketball\n"
             << " 3 - MLB Baseball\n"
             << " 4 - NHL Hockey\n"
             << "Select (1-4): ";

        int choice;
        if (!(cin >> choice)) {
            // Non-numeric selection
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Illegal selection – try again.\n\n";
            continue;
        }

        switch (choice) {
            case 1: return 53; // NFL
            case 2: return 13; // NBA
            case 3: return 25; // MLB
            case 4: return 23; // NHL
            default:
                cout << "Illegal selection – try again.\n\n";
        }
    }
}

int readInt(const char* prompt) {
    // Safe integer input (rejects letters/decimals/blank)
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;

        // Bad input: clear + flush garbage
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Illegal entry – please type a whole number.\n";
    }
}
