#include <bits/stdc++.h>
using namespace std;
int N;

// function for printing the solution
void printSol(vector<vector<int>> board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

/* Optimized isSafe function
isSafe function to check if current row contains or current left diagonal or current right diagonal contains any queen or not if
yes return false
else return true
*/

bool isSafe(int row, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)
{

    if (rows[row] == true || left_digonals[row + col] == true || Right_digonals[col - row + N - 1] == true)
    {
        return false;
    }

    return true;
}

// Recursive function to solve N-queen Problem
bool solve(vector<vector<int>> &board, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)
{
    // base Case : If all Queens are placed
    if (col >= N)
    {
        return true;
    }

    /* Consider this Column and move in all rows one by one */
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col, rows, left_digonals, Right_digonals) == true)
        {
            rows[i] = true;
            left_digonals[i + col] = true;
            Right_digonals[col - i + N - 1] = true;
            board[i][col] = 1; // placing the Queen in board[i][col]

            /* recur to place rest of the queens */

            if (solve(board, col + 1, rows, left_digonals, Right_digonals) == true)
            {
                return true;
            }

            // Backtracking
            rows[i] = false;
            left_digonals[i + col] = false;
            Right_digonals[col - i + N - 1] = false;
            board[i][col] = 0; // removing the Queen from board[i][col]
        }
    }

    return false;
}

int main()
{
    // Taking input from the user

    cout << "Enter the no of rows for the square Board : ";
    cin >> N;

    // board of size N*N
    vector<vector<int>> board(N, vector<int>(N, 0));

    // array to tell which rows are occupied
    vector<bool> rows(N, false);

    // arrays to tell which diagonals are occupied
    vector<bool> left_digonals(2 * N - 1, false);
    vector<bool> Right_digonals(2 * N - 1, false);

    bool ans = solve(board, 0, rows, left_digonals, Right_digonals);

    if (ans == true)
    {

        // printing the solution Board
        printSol(board);
    }
    else
    {
        cout << "Solution Does not Exist\n";
    }
}