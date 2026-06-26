#include <iostream>
#include <vector>
using namespace std;

void solve(int i, int j, int m, int n, string path, vector<string> &ans)
{
    if(i == m - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    if(i >= m || j >= n)
        return;

    solve(i + 1, j, m, n, path + "D", ans);

    solve(i, j + 1, m, n, path + "R", ans);
}

int main()
{
    int m, n;

    cout << "Enter rows and columns : ";
    cin >> m >> n;

    vector<string> ans;

    solve(0, 0, m, n, "", ans);

    cout << "\nStored Paths\n\n";

    for(string x : ans)
        cout << x << endl;

    return 0;
}