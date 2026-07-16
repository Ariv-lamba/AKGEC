#include <iostream>
#include <vector>
#include <algorithm>
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

    // Include current element
    output.push_back(candidates[index]);
    solve(candidates, target - candidates[index], index + 1, output, ans);
    output.pop_back();

    // Skip duplicate elements
    while(index + 1 < candidates.size() &&
          candidates[index] == candidates[index + 1])
    {
        index++;
    }

    // Exclude current element
    solve(candidates, target, index + 1, output, ans);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> output;

    solve(candidates, target, 0, output, ans);

    return ans;
}

int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> ans = combinationSum2(candidates, target);

    cout<<"Possible Combinations"<<endl;

    for(auto v : ans)
    {
        cout<<"{ ";

        for(int x : v)
            cout<<x<<" ";

        cout<<"}"<<endl;
    }

    return 0;
}