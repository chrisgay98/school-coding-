#include <iostream>
#include <cctype>
using namespace std;

bool isRPS(char c) {
    return c == 'R' || c == 'P' || c == 'S';
}

int main() {
    char player1, player2;
    char playAgain = 'Y';

    cout << "Enter R P or S for rock, paper or scissors\n";

    do {
        cout << "Player 1 (R P S): ";
        cin  >> player1;
        player1 = toupper(static_cast<unsigned char>(player1));

        cout << "Player 2 (R P S): ";
        cin  >> player2;
        player2 = toupper(static_cast<unsigned char>(player2));

        if (!isRPS(player1)) {
            cout << "Illegal selection for player 1\n";
        } else if (!isRPS(player2)) {
            cout << "Illegal selection for player 2\n";
        } else if (player1 == player2) {
            cout << "Tie game, nobody wins\n";
        } else if (player1 == 'R') {
            if (player2 == 'P')      cout << "Paper covers rock - player 2 wins\n";
            else /* player2 == 'S' */cout << "Rock breaks scissors - player 1 wins\n";
        } else if (player1 == 'P') {
            if (player2 == 'R')      cout << "Paper covers rock - player 1 wins\n";
            else /* player2 == 'S' */cout << "Scissors cut paper - player 2 wins\n";
        } else { // player1 == 'S'
            if (player2 == 'P')      cout << "Scissors cut paper - player 1 wins\n";
            else /* player2 == 'R' */cout << "Rock breaks scissors - player 2 wins\n";
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin  >> playAgain;
        playAgain = toupper(static_cast<unsigned char>(playAgain));
        cout << '\n';
    } while (playAgain == 'Y');

    return 0;
}
