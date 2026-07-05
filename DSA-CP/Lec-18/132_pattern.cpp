#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++)
        cin>>nums[i];

    stack<int> st;

    int second=INT_MIN;

    for(int i=n-1;i>=0;i--)
    {
        if(nums[i]<second)
        {
            cout<<"True";
            return 0;
        }

        while(!st.empty() && nums[i]>st.top())
        {
            second=st.top();
            st.pop();
        }

        st.push(nums[i]);
    }

    cout<<"False";

    return 0;
}