#include <iostream>
using namespace std;

int countPaths(int i, int j, int m, int n)
{
    if(i == m - 1 && j == n - 1)
        return 1;

    if(i >= m || j >= n)
        return 0;

    int down = countPaths(i + 1, j, m, n);

    int right = countPaths(i, j + 1, m, n);

    return down + right;
}

int main()
{
    int m, n;

    cin >> m >> n;

    cout << countPaths(0, 0, m, n);

    return 0;
}