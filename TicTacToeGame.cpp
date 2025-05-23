//
// Created by Aung Naing Thu on 5/18/2025.
//

#include <iostream>

using namespace std;

void displayBoard(int arr[3][3]) {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << (arr[i][j] == 0 ? "-" : (arr[i][j] == 1 ? "X" : "O")) << " ";
        }
        cout << endl;
    }
}

bool isValidMove(int arr[3][3], int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && arr[row][col] == 0;
}

// Function to check if there is a winner
bool checkWin(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] != 0 && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) return true; // Row check
        if (arr[0][i] != 0 && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) return true; // Column check
    }
    if (arr[0][0] != 0 && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) return true; // Diagonal check
    if (arr[0][2] != 0 && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) return true; // Anti-diagonal check
    return false;
}

int main() {
    cout << "Welcome to the Tic Tac Toe Game!" << endl;

    int arr[3][3] = {0};
    int row, col;
    int player = 1;  // Player 1 starts first

    for (int turn = 0; turn < 9; turn++) {
        displayBoard(arr);
        cout << "\nPlayer " << player << ", enter your move (row column): ";
        cin >> row >> col;

        row -= 1;  // Adjust for 0-based index
        col -= 1;

        while (!isValidMove(arr, row, col)) {
            cout << "Invalid move or space taken. Please enter a new move (row column): ";
            cin >> row >> col;
            row -= 1;
            col -= 1;
        }

        arr[row][col] = player;

        if (checkWin(arr)) {
            displayBoard(arr);
            cout << "Player " << player << " wins!" << endl;
            return 0; // End game early
        }

        player = (player == 1) ? 2 : 1;  // Switch player
    }

    displayBoard(arr);
    cout << "Game Over!" << endl;

    return 0;
}


