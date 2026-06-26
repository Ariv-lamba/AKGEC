#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[row][i] == num)
            return false;

        if(board[i][col] == num)
            return false;
    }

    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;

    for(int i = sr; i < sr + 3; i++)
    {
        for(int j = sc; j < sc + 3; j++)
        {
            if(board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == 0)
            {
                for(int num = 1; num <= 9; num++)
                {
                    if(isSafe(board, i, j, num))
                    {
                        board[i][j] = num;

                        if(solve(board))
                            return true;

                        board[i][j] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> board(9, vector<int>(9));

    cout << "Enter Sudoku (0 for empty cells):" << endl;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    if(solve(board))
    {
        cout << endl;

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No Solution";
    }

    return 0;
}