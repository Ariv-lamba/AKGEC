#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++)
        cin>>nums[i];

    int target;
    cin>>target;

    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(nums[mid]==target)
        {
            cout<<mid;
            return 0;
        }

        if(nums[low]<=nums[mid])
        {
            if(target>=nums[low] && target<nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        else
        {
            if(target>nums[mid] && target<=nums[high])
                low=mid+1;
            else
                high=mid-1;
        }
    }

    cout<<-1;

    return 0;
}