#include <iostream>
#include <vector>
using namespace std;

void fun(vector<int>& nums, int ind ,vector<int>&ds, vector<vector<int>>&ans ){
        if(ind == nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        fun(nums, ind+1, ds, ans);
        
        ds.pop_back();
        int x = ind;
        while(x+1<nums.size() && nums[x]==nums[x+1]){
            x++;
        }

        fun(nums, x+1, ds, ans);
    }

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> output;

    fun(nums, 0, output, ans);

    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = subsets(nums);

    cout<<"Subsets are : "<<endl;

    for(auto subset : ans)
    {
        cout<<"{ ";

        for(auto x : subset)
            cout<<x<<" ";

        cout<<"}"<<endl;
    }

    return 0;
}