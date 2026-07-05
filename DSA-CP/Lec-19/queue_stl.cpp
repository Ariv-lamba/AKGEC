#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"Front = "<<q.front()<<endl;
    cout<<"Back = "<<q.back()<<endl;

    q.pop();

    cout<<"Front = "<<q.front()<<endl;

    cout<<"Size = "<<q.size()<<endl;

    if(q.empty())
        cout<<"Queue is Empty";
    else
        cout<<"Queue is Not Empty";

    return 0;
}