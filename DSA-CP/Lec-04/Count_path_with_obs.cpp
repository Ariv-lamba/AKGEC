#include <iostream>
#include <vector>
using namespace std;

int countPaths(vector<vector<int>> &grid, int i, int j)
{
    int m = grid.size();
    int n = grid[0].size();

    if(i >= m || j >= n)
        return 0;

    if(grid[i][j] == 1)
        return 0;

    if(i == m - 1 && j == n - 1)
        return 1;

    int down = countPaths(grid, i + 1, j);

    int right = countPaths(grid, i, j + 1);

    return down + right;
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

    cout << countPaths(grid, 0, 0);

    return 0;
}