#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& nums,int index)
{
    if(index>=nums.size())
        return 0;

    // Rob Current House
    int rob=nums[index]+solve(nums,index+2);

    // Skip Current House
    int skip=solve(nums,index+1);

    return max(rob,skip);
}

int houseRobber(vector<int>& nums)
{
    return solve(nums,0);
}

int main()
{
    vector<int> nums={2,7,9,3,1};

    cout<<"Maximum Money = "<<houseRobber(nums);

    return 0;
}