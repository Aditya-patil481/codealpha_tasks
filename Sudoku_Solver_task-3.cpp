 #include <iostream>
#include <string>
using namespace std;

const int MAXN = 9;

// Grid settings, chosen by the user at the start of the program
int N;        // grid size (4, 6 or 9)
int BOXROWS;  // rows in one box
int BOXCOLS;  // columns in one box

// Asks the user to select the Sudoku grid size
bool selectGrid()
{
    int choice;

    cout << "Select Sudoku grid size:\n";
    cout << "  1. 4 x 4\n";
    cout << "  2. 6 x 6\n";
    cout << "  3. 9 x 9\n";
    cout << "\nEnter choice : ";
    cin >> choice;

    if(choice == 1)
    {
        N = 4; BOXROWS = 2; BOXCOLS = 2;
    }
    else if(choice == 2)
    {
        N = 6; BOXROWS = 2; BOXCOLS = 3;
    }
    else if(choice == 3)
    {
        N = 9; BOXROWS = 3; BOXCOLS = 3;
    }
    else
    {
        return false;
    }

    return true;
}

// Reads the puzzle pasted from the HTML generator.
// Digits are cells (0 or . = empty), spaces and new lines are ignored.
bool readPuzzle(int grid[MAXN][MAXN])
{
    int count = 0;
    char ch;

    while(count < N * N && cin.get(ch))
    {
        int value = -1;

        if(ch >= '0' && ch <= '9')
            value = ch - '0';
        else if(ch == '.')
            value = 0;

        if(value != -1)
        {
            if(value > N)
                return false;

            grid[count / N][count % N] = value;
            count++;
        }
    }

    return count == N * N;
}

void printLine()
{
    int width = N * 2 + (N / BOXCOLS) * 2 + 1;

    for(int i = 0; i < width; i++)
        cout << "-";

    cout << "\n";
}

void displayGrid(int grid[MAXN][MAXN], string title)
{
    cout << "\n==================== " << title << " ====================\n\n";

    for(int i = 0; i < N; i++)
    {
        if(i % BOXROWS == 0)
            printLine();

        for(int j = 0; j < N; j++)
        {
            if(j % BOXCOLS == 0)
                cout << "| ";

            if(grid[i][j] == 0)
                cout << ". ";
            else
                cout << grid[i][j] << " ";
        }

        cout << "|\n";
    }

    printLine();
}

bool isRowSafe(int grid[MAXN][MAXN], int row, int num)
{
    for(int col = 0; col < N; col++)
    {
        if(grid[row][col] == num)
            return false;
    }
    return true;
}

bool isColSafe(int grid[MAXN][MAXN], int col, int num)
{
    for(int row = 0; row < N; row++)
    {
        if(grid[row][col] == num)
            return false;
    }
    return true;
}

bool isBoxSafe(int grid[MAXN][MAXN], int startRow, int startCol, int num)
{
    for(int i = 0; i < BOXROWS; i++)
    {
        for(int j = 0; j < BOXCOLS; j++)
        {
            if(grid[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true;
}

bool isSafe(int grid[MAXN][MAXN], int row, int col, int num)
{
    return isRowSafe(grid, row, num) &&
           isColSafe(grid, col, num) &&
           isBoxSafe(grid, row - row % BOXROWS, col - col % BOXCOLS, num);
}

// Checks that the pasted clues do not already break a Sudoku rule.
bool cluesAreValid(int grid[MAXN][MAXN])
{
    for(int row = 0; row < N; row++)
    {
        for(int col = 0; col < N; col++)
        {
            int num = grid[row][col];

            if(num != 0)
            {
                grid[row][col] = 0;
                bool ok = isSafe(grid, row, col, num);
                grid[row][col] = num;

                if(!ok)
                    return false;
            }
        }
    }
    return true;
}

bool findEmptyCell(int grid[MAXN][MAXN], int &row, int &col)
{
    for(row = 0; row < N; row++)
    {
        for(col = 0; col < N; col++)
        {
            if(grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

// Backtracking solver
bool solveSudoku(int grid[MAXN][MAXN])
{
    int row, col;

    if(!findEmptyCell(grid, row, col))
        return true;

    for(int num = 1; num <= N; num++)
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
    int grid[MAXN][MAXN];

    cout << "=================================================\n";
    cout << "                 SUDOKU SOLVER\n";
    cout << "=================================================\n\n";

    if(!selectGrid())
    {
        cout << "\nInvalid choice!\n";
        return 1;
    }

    cout << "\nOpen sudoku_generator.html, choose the same grid size,\n";
    cout << "click 'Copy puzzle', then paste it here (" << N << " rows of "
         << N << " digits) and press Enter.\n\n";

    if(!readPuzzle(grid))
    {
        cout << "\nInvalid input! Please paste all " << N * N
             << " cells for a " << N << " x " << N << " grid.\n";
        return 1;
    }

    displayGrid(grid, "SUDOKU PUZZLE");

    if(!cluesAreValid(grid))
    {
        cout << "\nThe given numbers break Sudoku rules.\n";
        return 1;
    }

    if(solveSudoku(grid))
    {
        displayGrid(grid, "SUDOKU SOLUTION");
    }
    else
    {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}
