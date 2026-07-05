#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int target;
    cin>>target;

    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(arr[mid]==target)
        {
            cout<<"Found at "<<mid;
            return 0;
        }

        if(arr[mid]<target)
            low=mid+1;
        else
            high=mid-1;
    }

    cout<<"Not Found";

    return 0;
}