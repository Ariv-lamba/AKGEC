
// solution 1 
/*
class Solution {
public:
void findcomb_fixed(int ind, int target, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds) {
    if (ind == nums.size()) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }

    // Pick the current element
    if (nums[ind] <= target) { // Corrected: should be <=
        ds.push_back(nums[ind]);
        findcomb_fixed(ind + 1, target - nums[ind], nums, ans, ds);
        ds.pop_back();
    }

    // Don't pick the current element.
    // Crucially, skip all other duplicates of this element.
    int next_ind = ind + 1;
    while(next_ind < nums.size() && nums[next_ind] == nums[ind]){
        next_ind++;
    }
    findcomb_fixed(next_ind, target, nums, ans, ds);
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>>ans;
         vector<int>ok;
         sort(nums.begin(), nums.end());
         findcomb_fixed( 0, target, nums, ans, ok);
         return ans;
    }
};
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &arr,int i,int target,vector<int> &temp)
{
    if(target==0)
    {
        for(int x:temp)
            cout<<x<<" ";
        cout<<endl;
        return;
    }

    for(int j=i;j<arr.size();j++)
    {
        if(j>i && arr[j]==arr[j-1])
            continue;
        if(arr[j]>target)
            break;
        temp.push_back(arr[j]);
        solve(arr,j+1,target-arr[j],temp);
        temp.pop_back();
    }
}

int main()
{
    vector<int> arr={10,1,2,7,6,1,5};
    sort(arr.begin(),arr.end());
    vector<int> temp;
    solve(arr,0,8,temp);
    return 0;
}