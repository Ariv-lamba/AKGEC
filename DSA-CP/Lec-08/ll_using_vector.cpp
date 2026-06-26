#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:

    int data;
    Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

Node* create(vector<int> &arr)
{
    Node *head=new Node(arr[0]);

    Node *temp=head;

    for(int i=1;i<arr.size();i++)
    {
        Node *newNode=new Node(arr[i]);

        temp->next=newNode;

        temp=temp->next;
    }

    return head;
}

void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";

        head=head->next;
    }
}

int main()
{
    vector<int> arr={10,20,30,40,50};

    Node *head=create(arr);

    print(head);

    return 0;
}