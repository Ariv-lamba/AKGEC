#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int>& nums,int index,
           vector<int>& output,
           vector<vector<int>>& ans)
{
    if(index==nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Include
    output.push_back(nums[index]);
    solve(nums,index+1,output,ans);
    output.pop_back();

    // Skip duplicate elements
    while(index+1<nums.size() &&
          nums[index]==nums[index+1])
    {
        index++;
    }

    // Exclude
    solve(nums,index+1,output,ans);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    sort(nums.begin(),nums.end());

    vector<vector<int>> ans;
    vector<int> output;

    solve(nums,0,output,ans);

    return ans;
}

int main()
{
    vector<int> nums={1,2,2};

    vector<vector<int>> ans=subsetsWithDup(nums);

    cout<<"Unique Subsets"<<endl;

    for(auto v:ans)
    {
        cout<<"{ ";

        for(int x:v)
            cout<<x<<" ";

        cout<<"}"<<endl;
    }

    return 0;
}