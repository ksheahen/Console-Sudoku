//Sudoku Game in C++

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 9; //Constant variable for rows and columns

//print grid function
void printGrid(int grid[N][N]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(j == 3 || j == 6 ) {
                cout << " | ";

            }
            cout << grid[i][j] << " ";
        }
        if (i == 2 || i == 5) {
            cout << endl;
            for(int k = 0; k<N; k++) {
                cout << "---";
            }
        }
        cout << endl;
    }
}

//checks to see if the grid is filled out
bool isSolved(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

//allows user input to solve the game
void solveGame(int grid[N][N]) {

    int row;
    int col;
    int num;

    cout << "*** Sudoku Game ***" << endl;
    cout << "To play, enter the row and column number for each 0 to input your answer." << endl;

    while (true) {
        printGrid(grid); //calls printGrid function

        //User input for row variable
        cout << "Enter row:";
        cin >> row;
        while (row > 9 || row < 1) { //Verifying user input
            cout << "Invalid row - please enter a row number between 1 and 9." << endl;
            cout << "Enter row:";
            cin >> row;
        }

        //User input for column variable
        cout << "Enter column:";
        cin >> col;
        while (col > 9 || col < 1) { //Verifying user input
            cout << "Invalid column - please enter a column number between 1 and 9." << endl;
            cout << "Enter column:";
            cin >> col;
        }

        //User input for their answer
        cout << "Enter a number:";
        cin >> num;
        while (num > 9 || num < 0) { //Verifying user input (between 1 and 9, or 0 as a placeholder)
            cout << "Invalid number - please enter a number between 1 and 9." << endl;
            cout << "Enter a number:";
            cin >> num;
        }

        grid[row - 1][col - 1] = num; //User's answer is inputted into the array

        //Calls function isSolved
        if (isSolved(grid)) {

            string choice; //variable
            printGrid(grid); //calls function printGrid
            //Asks user if they would like to make any more changes
            cout << "Do you wish to make any more changes? (Yes/No)" << endl;
            cin >> choice;

            //user input to all uppercase
            transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

            //If their choice is no, ends the while loop. If yes, the while loop continues.
            if (choice == "NO") {
                break;
            }
        }

    }
}

//compares user entered input to answer
bool correctAns(int grid[N][N], int ans[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != ans[i][j]) {
                return false;
            }
        }
    }
    return true;

}

//MAIN FUNCTION
int main() {

    //Sudoku puzzle in an array
    int grid[N][N] = {{7,9,0,0,0,3,0,0,0},
                      {8,0,5,0,4,0,0,1,3},
                      {0,0,0,0,0,5,6,0,7},
                      {0,0,6,0,0,0,0,7,0},
                      {0,0,0,9,5,8,0,0,2},
                      {0,0,2,0,0,0,0,0,0},
                      {0,0,9,7,8,1,3,0,5},
                      {1,0,0,0,0,0,0,0,0},
                      {0,0,4,5,0,6,0,9,1}};

    //Answer key
    int ans[N][N] = {{7,9,1,8,6,3,2,5,4},
                     {8,6,5,2,4,7,9,1,3},
                     {2,4,3,1,9,5,6,8,7},
                     {5,8,6,3,1,2,4,7,9},
                     {4,3,7,9,5,8,1,6,2},
                     {9,1,2,6,7,4,5,3,8},
                     {6,2,9,7,8,1,3,4,5},
                     {1,5,8,4,3,9,7,2,6},
                     {3,7,4,5,2,6,8,9,1}};

    solveGame(grid); //calls solveGame function

    //calls correctAns function - verifying if user's puzzle is correct
    if (correctAns(grid, ans)) {
        cout << "Congratulations - You solved the puzzle!";
    } else {
        cout << "You did not solve the puzzle. Better luck next time!";
    }

}