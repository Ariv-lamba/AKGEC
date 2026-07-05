#include<iostream>
#include<stack>
using namespace std;

class MyQueue
{
public:

    stack<int> s1,s2;

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int ans=s2.top();
        s2.pop();

        return ans;
    }

    int peek()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.peek()<<endl;

    cout<<q.pop()<<endl;

    cout<<q.peek()<<endl;

    return 0;
}