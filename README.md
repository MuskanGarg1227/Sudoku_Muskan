# Sudoku_Muskan

Rules of SUDOKU:
1. Fill a 9x9 grid with digits 1 through 9 so that each digit appears exactly once per row.
2. Each digit must also appear exactly once per column.
3. Each 3x3 subgrid must contain all digits from 1 to 9 exactly once.

This project provides a Sudoku solver implemented in C++. 
It uses the backtracking algorithm to solve a standard 9x9 Sudoku puzzle. 
The program includes an interactive interface for entering the puzzle and displays the solved grid.

-CheckNo():
Purpose: Checks if placing a number in a cell is valid.

Checks:
1. Row: Number not repeated in the row.
2. Column: Number not repeated in the column.
3. 3x3 Subgrid: Number not present in the 3x3 box.


-SudokuSolver():
Purpose: Solves the Sudoku puzzle using backtracking.

1. Base Case: Return true if puzzle is solved.
2. Skip Filled Cells: Move to the next cell if current is filled.
3. Try Numbers: Place numbers 1-9 and recursively solve.
4. Backtracking: Undo the number if it leads to no solution and try the next.

-Backtracking Algorithm:

Concept:
1. Choice: Place a number in an empty cell.
2. Constraint Checking: Ensure the number is valid.
3. Recursion: Solve remaining cells.
4. Backtracking: Undo placement if it leads to no solution, and try the next option.
