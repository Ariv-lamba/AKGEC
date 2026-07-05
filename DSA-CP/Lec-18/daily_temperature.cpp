#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> temp(n);

    for(int i=0;i<n;i++)
        cin>>temp[i];

    vector<int> ans(n);

    stack<int> st;

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && temp[st.top()]<=temp[i])
            st.pop();

        if(st.empty())
            ans[i]=0;
        else
            ans[i]=st.top()-i;

        st.push(i);
    }

    for(int x:ans)
        cout<<x<<" ";

    return 0;
}