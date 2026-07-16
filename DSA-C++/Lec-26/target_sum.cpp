#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& nums,int index,int sum,int target)
{
    if(index==nums.size())
    {
        if(sum==target)
            return 1;
        else
            return 0;
    }

    // Positive Sign
    int plus=solve(nums,index+1,sum+nums[index],target);

    // Negative Sign
    int minus=solve(nums,index+1,sum-nums[index],target);

    return plus+minus;
}

int findTargetSumWays(vector<int>& nums,int target)
{
    return solve(nums,0,0,target);
}

int main()
{
    vector<int> nums={1,1,1,1,1};

    int target=3;

    cout<<"Total Ways = "<<findTargetSumWays(nums,target);

    return 0;
}