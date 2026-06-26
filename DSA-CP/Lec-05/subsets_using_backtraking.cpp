#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr, int i,vector<int> &temp,
           vector<vector<int>> &ans)
{
    if(i == arr.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[i]);
    solve(arr,i+1,temp,ans);
    temp.pop_back();
    solve(arr,i+1,temp,ans);
}

int main()
{
    vector<int> arr={1,2,3};
    vector<int> temp;
    vector<vector<int>> ans;
    solve(arr,0,temp,ans);
    for(auto v:ans)
    {
        for(int x:v)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}