#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums, int index,
           vector<int>& output,
           vector<vector<int>>& ans)
{
    // Base Case
    if(index == nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Include
    output.push_back(nums[index]);
    solve(nums, index + 1, output, ans);

    // Backtrack
    output.pop_back();

    // Exclude
    solve(nums, index + 1, output, ans);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> output;

    solve(nums, 0, output, ans);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = subsets(nums);

    cout << "Subsets are\n";

    for(auto subset : ans)
    {
        cout << "{ ";

        for(int x : subset)
            cout << x << " ";

        cout << "}" << endl;
    }

    return 0;
}