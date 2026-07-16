#include <iostream>
using namespace std;

int solve(int row, int col, int m, int n)
{
    // Destination reached
    if(row == m - 1 && col == n - 1)
        return 1;

    // Out of boundary
    if(row >= m || col >= n)
        return 0;

    // Move Down
    int down = solve(row + 1, col, m, n);

    // Move Right
    int right = solve(row, col + 1, m, n);

    return down + right;
}

int uniquePaths(int m, int n)
{
    return solve(0, 0, m, n);
}

int main()
{
    int m = 3;
    int n = 3;

    cout << "Total Paths = " << uniquePaths(m, n);

    return 0;
}