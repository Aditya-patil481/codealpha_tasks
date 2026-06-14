#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 9;

int puzzles[3][9][9] =
{
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    },

    {
        {0,0,0,2,6,0,7,0,1},
        {6,8,0,0,7,0,0,9,0},
        {1,9,0,0,0,4,5,0,0},
        {8,2,0,1,0,0,0,4,0},
        {0,0,4,6,0,2,9,0,0},
        {0,5,0,0,0,3,0,2,8},
        {0,0,9,3,0,0,0,7,4},
        {0,4,0,0,5,0,0,3,6},
        {7,0,3,0,1,8,0,0,0}
    },

    {
        {0,2,0,6,0,8,0,0,0},
        {5,8,0,0,0,9,7,0,0},
        {0,0,0,0,4,0,0,0,0},
        {3,7,0,0,0,0,5,0,0},
        {6,0,0,0,0,0,0,0,4},
        {0,0,8,0,0,0,0,1,3},
        {0,0,0,0,2,0,0,0,0},
        {0,0,9,8,0,0,0,3,6},
        {0,0,0,3,0,6,0,9,0}
    }
};

void displayPuzzle(int grid[SIZE][SIZE])
{
    cout << "\n==================== SUDOKU PUZZLE ====================\n\n";

    for(int i = 0; i < SIZE; i++)
    {
        if(i % 3 == 0)
            cout << "-------------------------------------\n";

        for(int j = 0; j < SIZE; j++)
        {
            if(j % 3 == 0)
                cout << "| ";

            if(grid[i][j] == 0)
                cout << ". ";
            else
                cout << grid[i][j] << " ";
        }

        cout << "|\n";
    }

    cout << "-------------------------------------\n";
}

void printGrid(int grid[SIZE][SIZE])
{
    cout << "\n==================== SUDOKU SOLUTION ====================\n\n";

    for(int i = 0; i < SIZE; i++)
    {
        if(i % 3 == 0)
            cout << "-------------------------------------\n";

        for(int j = 0; j < SIZE; j++)
        {
            if(j % 3 == 0)
                cout << "| ";

            cout << grid[i][j] << " ";
        }

        cout << "|\n";
    }

    cout << "-------------------------------------\n";
}

bool isRowSafe(int grid[SIZE][SIZE], int row, int num)
{
    for(int col = 0; col < SIZE; col++)
    {
        if(grid[row][col] == num)
            return false;
    }
    return true;
}

bool isColSafe(int grid[SIZE][SIZE], int col, int num)
{
    for(int row = 0; row < SIZE; row++)
    {
        if(grid[row][col] == num)
            return false;
    }
    return true;
}

bool isBoxSafe(int grid[SIZE][SIZE], int startRow, int startCol, int num)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true;
}

bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{
    return isRowSafe(grid, row, num) &&
           isColSafe(grid, col, num) &&
           isBoxSafe(grid,
                     row - row % 3,
                     col - col % 3,
                     num);
}

bool findEmptyCell(int grid[SIZE][SIZE], int &row, int &col)
{
    for(row = 0; row < SIZE; row++)
    {
        for(col = 0; col < SIZE; col++)
        {
            if(grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool solveSudoku(int grid[SIZE][SIZE])
{
    int row, col;

    if(!findEmptyCell(grid, row, col))
        return true;

    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if(solveSudoku(grid))
                return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    srand(time(0));

    int grid[SIZE][SIZE];

    int choice = rand() % 3;

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            grid[i][j] = puzzles[choice][i][j];
        }
    }

    cout << "=================================================\n";
    cout << "                 SUDOKU SOLVER\n";
    cout << "=================================================\n";

    displayPuzzle(grid);

    if(solveSudoku(grid))
    {
        printGrid(grid);
    }
    else
    {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}