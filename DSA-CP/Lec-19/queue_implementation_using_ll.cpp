#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class Queue
{
public:

    Node *front;
    Node *rear;

    Queue()
    {
        front=NULL;
        rear=NULL;
    }

    void push(int x)
    {
        Node *temp=new Node(x);

        if(front==NULL)
        {
            front=rear=temp;
            return;
        }

        rear->next=temp;
        rear=temp;
    }

    void pop()
    {
        if(front==NULL)
            return;

        Node *temp=front;

        front=front->next;

        delete temp;

        if(front==NULL)
            rear=NULL;
    }

    int Front()
    {
        if(front==NULL)
            return -1;

        return front->data;
    }

    bool empty()
    {
        return front==NULL;
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.Front()<<endl;

    q.pop();

    cout<<q.Front()<<endl;

    return 0;
}