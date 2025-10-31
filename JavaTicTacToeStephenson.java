// Program Name: JavaTicTacToeStephenson
// Programmer:   Christian Stephenson
// Class:        CIS-084 Java Programming
// Date:         October 30, 2025
// Version:      1.0
//
// Notes:
//  - Uses a 3x3 char[][] board initialized to '1'..'9'.
//  - Validates input (1-9, unused square).
//  - Alternates X and O until win or tie.
//  - Subroutines: displayTicTacToe(board), checkForWinningGame(board).
//  - Extra credit: fancy board with | and - separators.
import java.util.Scanner;

public class JavaTicTacToeStephenson {

    static char[][] board = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);

        int squareCounter = 0;
        char gameWinner = '-';
        char player = selectStartingPlayer();

        System.out.println("The starting player is using " + player);
        System.out.println("Enter a 1 through 9 to select a square");

        while (squareCounter < 9 && gameWinner != 'X' && gameWinner != 'O') {
            System.out.println("--------------------------------");
            displayTicTacToe(board);
            System.out.print("Player " + player + ", enter a number (1-9): ");

            String token = stdin.nextLine().trim();
            if (token.isEmpty()) {
                System.out.println("Illegal value, try again");
                continue;
            }
            char inputCharacter = token.charAt(0);

            int choice = inputCharacter - '1'; // '1'..'9' -> 0..8
            int row = choice / 3;
            int col = choice % 3;

            if (choice < 0 || choice > 8) {
                System.out.println("Illegal value, try again");
                continue;
            }
            if (board[row][col] == 'X' || board[row][col] == 'O') {
                System.out.println("This space has already been used, try again");
                continue;
            }

            board[row][col] = player;
            squareCounter++;

            // Check for winner
            gameWinner = checkForWinningGame(board);
            if (gameWinner == 'X' || gameWinner == 'O' || squareCounter == 9) {
                break;
            }

            // Switch player
            player = (player == 'X') ? 'O' : 'X';
        }

        displayTicTacToe(board);
        System.out.println();
        if (gameWinner == 'X' || gameWinner == 'O') {
            System.out.printf("Player %c wins the game%n%n", gameWinner);
        } else {
            System.out.printf("Tie game%n%n");
        }

        stdin.close();
    }

    // --- Fancy board for extra credit ---
    public static void displayTicTacToe(char[][] b) {
        System.out.println();
        System.out.println("  Tic-Tac-Toe");
        for (int r = 0; r < 3; r++) {
            // Row content
            for (int c = 0; c < 3; c++) {
                System.out.print(" " + b[r][c] + " ");
                if (c < 2) System.out.print("|");
            }
            System.out.println();
            // Separator (not after last row)
            if (r < 2) System.out.println("---+---+---");
        }
    }

    // --- Return 'X' or 'O' if someone has won; '-' otherwise ---
    public static char checkForWinningGame(char[][] b) {
        // Rows
        for (int r = 0; r < 3; r++) {
            char p = b[r][0];
            if (p == 'X' || p == 'O') {
                if (b[r][1] == p && b[r][2] == p) return p;
            }
        }
        // Columns
        for (int c = 0; c < 3; c++) {
            char p = b[0][c];
            if (p == 'X' || p == 'O') {
                if (b[1][c] == p && b[2][c] == p) return p;
            }
        }
        // Diagonals
        char p = b[0][0];
        if ((p == 'X' || p == 'O') && b[1][1] == p && b[2][2] == p) return p;

        p = b[0][2];
        if ((p == 'X' || p == 'O') && b[1][1] == p && b[2][0] == p) return p;

        return '-';
    }

    private static char selectStartingPlayer() {
        int selectFirstPlayer = (int)(Math.random() * 2); // 0 or 1
        return (selectFirstPlayer % 2 == 1) ? 'X' : 'O';
    }
}
