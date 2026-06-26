#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr, int i, vector<int>ans)
{
    if(i == arr.size())
    {
        for(int x : ans)
            cout << x << " ";
        cout << endl;
        return;
    }
    solve(arr, i + 1, ans);
    ans.push_back(arr[i]);
    solve(arr, i + 1, ans);
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<int> ans;
    solve(arr,0,ans);
}