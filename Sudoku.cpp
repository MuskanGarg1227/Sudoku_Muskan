#include <iostream>
using namespace std;

// Size of the Sudoku grid
#define N 9

// Function to print the Sudoku grid
void Print(int grid[N][N]) {
    cout << "Current Sudoku Grid:" << endl;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if we can put the number at grid[row][col]
bool CheckNo(int grid[N][N], int row, int col, int num) {
    // Check if 'num' is not in the current row
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Check if 'num' is not in the current column
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // Check if 'num' is not in the current 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to solve Sudoku using backtracking
bool SudokuSolver(int grid[N][N], int row, int col) {
    // If we have reached the last row, the puzzle is solved
    if (row == N - 1 && col == N)
        return true;

    // If we reach the end of a row, move to the next row
    if (col == N) {
        row++;
        col = 0;
    }

    // Skip cells that already have a number
    if (grid[row][col] != 0)
        return SudokuSolver(grid, row, col + 1);

    // Try placing numbers 1-9 in the current empty cell
    for (int num = 1; num <= 9; num++) {
        if (CheckNo(grid, row, col, num)) {
            // Place the number
            grid[row][col] = num;

            // Recursively solve for the next cell
            if (SudokuSolver(grid, row, col + 1))
                return true;
        }

        // If placing num doesn't lead to a solution, backtrack
        grid[row][col] = 0;
    }

    // If no number works, return false
    return false;
}



// Driver code
int main() {
    int grid[N][N];

    // Take input from the user
    cout << "Enter the Sudoku puzzle (use 0 for empty cells):" << endl;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
    }

    // Solve the Sudoku
    if (SudokuSolver(grid, 0, 0)) {
        cout << "\nSolved Sudoku grid:" << endl;
        Print(grid);
    } 
    else {
        cout << "No solution exists for the given Sudoku puzzle.";
    
    }
    return 0;
}
