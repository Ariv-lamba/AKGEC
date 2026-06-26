#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &arr,int i,int sum,int target)
{
    if(i==arr.size())
    {
        if(sum==target)
            return 1;
        return 0;
    }
    int plus=solve(arr,i+1,sum+arr[i],target);
    int minus=solve(arr,i+1,sum-arr[i],target);
    return plus+minus;
}

int main()
{
    vector<int> arr={1,1,1,1,1};
    int target=3;
    cout<<solve(arr,0,0,target);
    return 0;
}

// here is 2nd solution we discussed in class 
/*
class Solution {
public:

   void fun(vector<int>&nums, int i , int p, int &count){
    if(i == nums.size()){
        if(p == 0)count++;
        return;
    }
    fun(nums, i+1, p-nums[i], count);
    fun(nums, i+1, p, count);
   }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i =0; i<n; i++){
            sum += nums[i]; 
        }
        if((sum + target) % 2 != 0) return 0;
        if(sum<abs(target))return 0;
        int p = (sum + target)/2 ; 
        int count =0;
         fun(nums, 0, p, count);
         return count;
        // p - n = t
        // p + n = s 
        // p = (t+s)/2
    }
};



*/