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

    for(int i=0;i<n;i++)
    {
        int sum=0;

        for(int j=i;j<n;j++)
        {
            sum+=arr[j];

            if(sum==k)
            {
                for(int x=i;x<=j;x++)
                    cout<<arr[x]<<" ";

                cout<<endl;
            }
        }
    }

    return 0;
}