#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &arr, vector<int> &temp, vector<int> &used)
{
    if(temp.size() == arr.size())
    {
        for(int x : temp)
            cout << x << " ";

        cout << endl;
        return;
    }

    for(int i = 0; i < arr.size(); i++)
    {
        if(used[i] == 1)
            continue;

        if(i > 0 && arr[i] == arr[i - 1] && used[i - 1] == 0)
            continue;

        used[i] = 1;
        temp.push_back(arr[i]);

        solve(arr, temp, used);

        temp.pop_back();
        used[i] = 0;
    }
}

int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements : ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    vector<int> temp;
    vector<int> used(n, 0);
    solve(arr, temp, used);
    return 0;
}