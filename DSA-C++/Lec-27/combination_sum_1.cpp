#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& candidates, int target, int index,
           vector<int>& output, vector<vector<int>>& ans)
{
    if(target == 0)
    {
        ans.push_back(output);
        return;
    }

    if(index == candidates.size() || target < 0)
        return;

    // Include
    output.push_back(candidates[index]);
    solve(candidates, target - candidates[index], index, output, ans);
    output.pop_back();

    // Exclude
    solve(candidates, target, index + 1, output, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> output;

    solve(candidates, target, 0, output, ans);

    return ans;
}

int main()
{
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(candidates, target);

    cout<<"Combinations are : "<<endl;

    for(auto comb : ans)
    {
        cout<<"{ ";

        for(auto x : comb)
            cout<<x<<" ";

        cout<<"}"<<endl;
    }

    return 0;
}