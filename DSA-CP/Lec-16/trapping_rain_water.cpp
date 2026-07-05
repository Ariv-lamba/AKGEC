#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> height(n);

    for(int i=0;i<n;i++)
        cin>>height[i];

    stack<int> st;

    int water=0;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && height[i]>height[st.top()])
        {
            int mid=st.top();
            st.pop();

            if(st.empty())
                break;

            int left=st.top();

            int width=i-left-1;

            int h=min(height[left],height[i])-height[mid];

            water+=width*h;
        }

        st.push(i);
    }

    cout<<water;

    return 0;
}