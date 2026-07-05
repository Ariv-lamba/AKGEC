#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    stack<int> st;

    for(int x:arr)
    {
        bool destroyed=false;

        while(!st.empty() && st.top()>0 && x<0)
        {
            if(abs(st.top())<abs(x))
            {
                st.pop();
            }
            else if(abs(st.top())==abs(x))
            {
                st.pop();
                destroyed=true;
                break;
            }
            else
            {
                destroyed=true;
                break;
            }
        }

        if(!destroyed)
            st.push(x);
    }

    vector<int> ans;

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    if(ans.empty())
    {
        cout<<"Empty";
        return 0;
    }

    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";

    return 0;
}