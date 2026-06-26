#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &grid, int i, int j, string path, vector<string> &ans)
{
    int m = grid.size();
    int n = grid[0].size();

    if(i >= m || j >= n)
        return;

    if(grid[i][j] == 1)
        return;

    if(i == m - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    solve(grid, i + 1, j, path + "D", ans);

    solve(grid, i, j + 1, path + "R", ans);
}

int main()
{
    int m, n;

    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    vector<string> ans;

    solve(grid, 0, 0, "", ans);

    for(string x : ans)
        cout << x << endl;

    return 0;
}