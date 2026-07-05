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

    int k;
    cin>>k;

    bool found=false;

    for(int i=0;i<n;i++)
    {
        int sum=0;

        for(int j=i;j<n;j++)
        {
            sum+=arr[j];

            if(sum==k)
            {
                found=true;
                break;
            }
        }

        if(found)
            break;
    }

    if(found)
        cout<<"Found";
    else
        cout<<"Not Found";

    return 0;
}