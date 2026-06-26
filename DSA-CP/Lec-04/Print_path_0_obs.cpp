#include <iostream>
#include <string>
using namespace std;

void printPaths(int i, int j, int m, int n, string path)
{
    if(i == m - 1 && j == n - 1)
    {
        cout << path << endl;
        return;
    }

    if(i >= m || j >= n)
        return;

    printPaths(i + 1, j, m, n, path + "D");

    printPaths(i, j + 1, m, n, path + "R");
}

int main()
{
    int m, n;

    cout << "Enter rows and columns : ";
    cin >> m >> n;

    cout << "\nAll Paths\n\n";

    printPaths(0, 0, m, n, "");

    return 0;
}