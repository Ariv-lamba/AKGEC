#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int sum=0;
    int maxSum=INT_MIN;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        maxSum=max(maxSum,sum);
    }

    cout<<"Maximum Prefix Sum = "<<maxSum;

    return 0;
}