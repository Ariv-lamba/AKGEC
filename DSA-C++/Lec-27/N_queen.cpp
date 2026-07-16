#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n)
{
    int x = row;
    int y = col;

    // Upper Left Diagonal
    while(x >= 0 && y >= 0)
    {
        if(board[x][y] == 'Q')
            return false;

        x--;
        y--;
    }

    // Left Side
    x = row;
    y = col;

    while(y >= 0)
    {
        if(board[x][y] == 'Q')
            return false;

        y--;
    }

    // Lower Left Diagonal
    x = row;
    y = col;

    while(x < n && y >= 0)
    {
        if(board[x][y] == 'Q')
            return false;

        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<string>& board,
           vector<vector<string>>& ans, int n)
{
    if(col == n)
    {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++)
    {
        if(isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';

            solve(col + 1, board, ans, n);

            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;

    vector<string> board(n);

    string s(n,'.');

    for(int i=0;i<n;i++)
        board[i]=s;

    solve(0, board, ans, n);

    return ans;
}

int main()
{
    int n = 4;

    vector<vector<string>> ans = solveNQueens(n);

    cout<<"Total Solutions = "<<ans.size()<<endl;

    for(int i=0;i<ans.size();i++)
    {
        cout<<"\nSolution "<<i+1<<endl;

        for(string row : ans[i])
            cout<<row<<endl;
    }

    return 0;
}