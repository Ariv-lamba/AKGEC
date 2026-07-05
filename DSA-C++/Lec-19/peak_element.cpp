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

    int low=0;
    int high=n-1;

    while(low<high)
    {
        int mid=low+(high-low)/2;

        if(nums[mid]>nums[mid+1])
            high=mid;
        else
            low=mid+1;
    }

    cout<<"Peak Element = "<<nums[low];

    return 0;
}