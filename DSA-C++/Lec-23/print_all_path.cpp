#include <iostream>
#include <string>
using namespace std;

void solve(int row, int col, int m, int n, string path)
{
    // Destination
    if(row == m - 1 && col == n - 1)
    {
        cout << path << endl;
        return;
    }

    // Out of boundary
    if(row >= m || col >= n)
        return;

    // Down
    solve(row + 1, col, m, n, path + 'D');

    // Right
    solve(row, col + 1, m, n, path + 'R');
}

void printPaths(int m, int n)
{
    solve(0, 0, m, n, "");
}

int main()
{
    int m = 3;
    int n = 3;

    cout << "All Possible Paths\n";

    printPaths(m, n);

    return 0;
}