#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> previousSmaller(vector<int> &height)
{
    int n = height.size();

    vector<int> left(n);

    stack<int> st;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && height[st.top()]>=height[i])
            st.pop();

        if(st.empty())
            left[i]=-1;
        else
            left[i]=st.top();

        st.push(i);
    }

    return left;
}

vector<int> nextSmaller(vector<int> &height)
{
    int n = height.size();

    vector<int> right(n);

    stack<int> st;

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && height[st.top()]>=height[i])
            st.pop();

        if(st.empty())
            right[i]=n;
        else
            right[i]=st.top();

        st.push(i);
    }

    return right;
}

int main()
{
    int n;
    cin>>n;

    vector<int> height(n);

    for(int i=0;i<n;i++)
        cin>>height[i];

    vector<int> left = previousSmaller(height);
    vector<int> right = nextSmaller(height);

    int ans = 0;

    for(int i=0;i<n;i++)
    {
        int width = right[i] - left[i] - 1;

        ans = max(ans, width * height[i]);
    }

    cout<<ans;

    return 0;
}