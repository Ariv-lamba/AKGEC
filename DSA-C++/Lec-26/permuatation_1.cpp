#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& nums,int index,
           vector<vector<int>>& ans)
{
    if(index==nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i=index;i<nums.size();i++)
    {
        swap(nums[index],nums[i]);

        solve(nums,index+1,ans);

        swap(nums[index],nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ans;

    solve(nums,0,ans);

    return ans;
}

int main()
{
    vector<int> nums={1,2,3};

    vector<vector<int>> ans=permute(nums);

    cout<<"Permutations"<<endl;

    for(auto v:ans)
    {
        cout<<"{ ";

        for(int x:v)
            cout<<x<<" ";

        cout<<"}"<<endl;
    }

    return 0;
}