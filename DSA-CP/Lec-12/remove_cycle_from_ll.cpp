#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* createLL(vector<int> &arr)
{
    if(arr.size()==0)
        return NULL;

    Node* head=new Node(arr[0]);
    Node* temp=head;

    for(int i=1;i<arr.size();i++)
    {
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }

    return head;
}

void print(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void removeCycle(Node* head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            slow=head;

            // Cycle starts at head
            if(slow==fast)
            {
                while(fast->next!=slow)
                    fast=fast->next;

                fast->next=NULL;
                return;
            }

            while(slow->next!=fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }

            fast->next=NULL;
            return;
        }
    }
}

bool detectCycle(Node* head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
            return true;
    }

    return false;
}

int main()
{
    vector<int> arr={10,20,30,40,50};

    Node* head=createLL(arr);

    // Create Cycle
    head->next->next->next->next->next=head->next;

    cout<<"Before Removing"<<endl;

    if(detectCycle(head))
        cout<<"Cycle Present"<<endl;

    removeCycle(head);

    cout<<"After Removing"<<endl;

    if(detectCycle(head))
        cout<<"Cycle Present"<<endl;
    else
        cout<<"No Cycle"<<endl;

    print(head);

    return 0;
}