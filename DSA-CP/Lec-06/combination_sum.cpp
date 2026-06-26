#include <iostream>
#include <vector>
using namespace std;

/*
void solve(vector<int> &arr,int i,int target,vector<int> &temp)
{
    if(target==0)
    {
        for(int x:temp)
            cout<<x<<" ";
        cout<<endl;
        return;
    }

    if(i==arr.size() || target<0)
        return;

    temp.push_back(arr[i]);
    solve(arr,i,target-arr[i],temp);
    temp.pop_back();

    solve(arr,i+1,target,temp);
}
*/

       void fun(vector<int> &arr, int ind, int target, vector<vector<int>>&ans, vector<int>ok){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ok);
            }
            return;
        }
        // pick 
        if(arr[ind]<=target){
            ok.push_back(arr[ind]);
            fun(arr,ind,  target-arr[ind], ans, ok);
            ok.pop_back();
        }
        fun(arr, ind+1, target, ans, ok);
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        // Your code here
        vector<vector<int>>ans;
        vector<int>ok;
        fun(arr, 0, target, ans, ok);
        return ans;
    }

int main()
{
    vector<int> arr={2,3,6,7};
    vector<vector<int>>ans;
    vector<int> temp;

    fun(arr,0,7,ans,temp);
    // if you want to print output you can do this
    for(auto v:ans)
    {
        for(int x:v)
            cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}