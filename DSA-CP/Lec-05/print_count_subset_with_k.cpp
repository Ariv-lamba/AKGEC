#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr,int i,int sum,int k,vector<int> &temp, int &count)
{
    if(i==arr.size())
    {
        if(sum==k)
        {
            for(int x:temp)
                cout<<x<<" ";

            cout<<endl;
            count++;
        }

        return;
    }

    temp.push_back(arr[i]);
    solve(arr,i+1,sum+arr[i],k,temp, count);
    temp.pop_back();
    solve(arr,i+1,sum,k,temp, count);
}

int main()
{
    vector<int> arr={1,2,3,4};
    vector<int> temp;
    int count =0;
    solve(arr,0,0,5,temp, count);
    cout << count << endl;
    return 0;
}