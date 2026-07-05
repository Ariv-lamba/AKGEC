#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> previousSmaller(vector<int> &arr)
{
    int n=arr.size();

    vector<int> left(n);

    stack<int> st;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();

        if(st.empty())
            left[i]=-1;
        else
            left[i]=st.top();

        st.push(i);
    }

    return left;
}

vector<int> nextSmaller(vector<int> &arr)
{
    int n=arr.size();

    vector<int> right(n);

    stack<int> st;

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
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

    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> left=previousSmaller(arr);
    vector<int> right=nextSmaller(arr);

    long long ans=0;

    for(int i=0;i<n;i++)
    {
        long long l=i-left[i];
        long long r=right[i]-i;

        ans+=1LL*arr[i]*l*r;
    }

    cout<<ans;

    return 0;
}