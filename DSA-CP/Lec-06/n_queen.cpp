#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }

    int i = row;
    int j = col;

    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 1)
            return false;

        i--;
        j--;
    }

    i = row;
    j = col;

    while(i >= 0 && j < n)
    {
        if(board[i][j] == 1)
            return false;

        i--;
        j++;
    }

    return true;
}

void solve(vector<vector<int>> &board, int row, int n)
{
    if(row == n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }

            cout << endl;
        }

        cout << endl;

        return;
    }

    for(int col = 0; col < n; col++)
    {
        if(isSafe(board, row, col, n))
        {
            board[row][col] = 1;

            solve(board, row + 1, n);

            board[row][col] = 0;
        }
    }
}

int main()
{
    int n;

    cout << "Enter value of n : ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(board, 0, n);
    return 0;
}