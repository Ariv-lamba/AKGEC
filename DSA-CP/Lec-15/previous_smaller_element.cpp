#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    vector<int> ans(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    stack<int> st;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()>=arr[i])
            st.pop();

        if(st.empty())
            ans[i]=-1;
        else
            ans[i]=st.top();

        st.push(arr[i]);
    }

    for(int x:ans)
        cout<<x<<" ";

    return 0;
}