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

    vector<int> prefix(n);
    vector<int> suffix(n);
    vector<int> ans(n);

    prefix[0]=nums[0];

    for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]*nums[i];

    suffix[n-1]=nums[n-1];

    for(int i=n-2;i>=0;i--)
        suffix[i]=suffix[i+1]*nums[i];

    for(int i=0;i<n;i++)
    {
        if(i==0)
            ans[i]=suffix[1];
        else if(i==n-1)
            ans[i]=prefix[n-2];
        else
            ans[i]=prefix[i-1]*suffix[i+1];
    }

    for(int x:ans)
        cout<<x<<" ";

    return 0;
}