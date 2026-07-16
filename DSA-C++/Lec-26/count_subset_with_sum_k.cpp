#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& nums, int index, int target)
{
    if(target == 0)
        return 1;

    if(index == nums.size() || target < 0)
        return 0;

    // Include
    int include = solve(nums, index + 1, target - nums[index]);

    // Exclude
    int exclude = solve(nums, index + 1, target);

    return include + exclude;
}

int countSubsetSumK(vector<int>& nums, int target)
{
    return solve(nums, 0, target);
}

int main()
{
    vector<int> nums = {1,2,3,4};
    int target = 5;

    cout<<"Total Subsets = "<<countSubsetSumK(nums,target);

    return 0;
}