#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums,int index,int target,
           vector<int>& output)
{
    if(target==0)
    {
        cout<<"{ ";

        for(int x:output)
            cout<<x<<" ";

        cout<<"}"<<endl;
        return;
    }

    if(index==nums.size() || target<0)
        return;

    // Include
    output.push_back(nums[index]);
    solve(nums,index+1,target-nums[index],output);
    output.pop_back();

    // Exclude
    solve(nums,index+1,target,output);
}

void printSubsetSumK(vector<int>& nums,int target)
{
    vector<int> output;
    solve(nums,0,target,output);
}

int main()
{
    vector<int> nums={1,2,3,4};
    int target=5;

    cout<<"Subsets are"<<endl;

    printSubsetSumK(nums,target);

    return 0;
}