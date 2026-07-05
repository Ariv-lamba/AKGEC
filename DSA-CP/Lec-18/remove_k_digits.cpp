#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
    string num;
    cin>>num;

    int k;
    cin>>k;

    stack<char> st;

    for(char ch:num)
    {
        while(!st.empty() && k>0 && st.top()>ch)
        {
            st.pop();
            k--;
        }

        st.push(ch);
    }

    while(k>0)
    {
        st.pop();
        k--;
    }

    string ans="";

    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    int i=0;

    while(i<ans.size() && ans[i]=='0')
        i++;

    ans=ans.substr(i);

    if(ans=="")
        cout<<0;
    else
        cout<<ans;

    return 0;
}