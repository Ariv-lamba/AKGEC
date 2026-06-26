#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int i)
{
    if(i >= nums.size())
        return 0;

    int take = nums[i] + solve(nums, i + 2);

    int skip = solve(nums, i + 1);

    return max(take, skip);
}

int houseRobber(vector<int> &nums)
{
    return solve(nums, 0);
}

int main()
{
    int n;

    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter money in each house:\n";

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Maximum Money = " << houseRobber(nums);

    return 0;
}