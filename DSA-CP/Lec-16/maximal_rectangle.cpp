#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> previousSmaller(vector<int> &height)
{
    int n=height.size();

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
    int n=height.size();

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

int largestRectangle(vector<int> &height)
{
    vector<int> left=previousSmaller(height);

    vector<int> right=nextSmaller(height);

    int ans=0;

    for(int i=0;i<height.size();i++)
    {
        int width=right[i]-left[i]-1;

        ans=max(ans,width*height[i]);
    }

    return ans;
}

int main()
{
    int row,col;

    cin>>row>>col;

    vector<vector<int>> matrix(row,vector<int>(col));

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>matrix[i][j];

    vector<int> height(col,0);

    int ans=0;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]==0)
                height[j]=0;
            else
                height[j]++;
        }

        ans=max(ans,largestRectangle(height));
    }

    cout<<ans;

    return 0;
}