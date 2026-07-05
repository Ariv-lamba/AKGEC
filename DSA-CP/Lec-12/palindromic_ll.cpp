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
        data = val;
        next = NULL;
    }
};

Node* createLL(vector<int> &arr)
{
    if(arr.size()==0)
        return NULL;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=1;i<arr.size();i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
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

Node* reverse(Node* head)
{
    Node* prev=NULL;

    while(head)
    {
        Node* nextNode=head->next;
        head->next=prev;
        prev=head;
        head=nextNode;
    }

    return prev;
}

bool isPalindrome(Node* head)
{
    if(head==NULL || head->next==NULL)
        return true;

    Node* slow=head;
    Node* fast=head;

    // Find Middle
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    // Reverse Second Half
    Node* secondHalf=reverse(slow->next);

    Node* firstHalf=head;
    Node* temp=secondHalf;

    // Compare Both Halves
    while(temp)
    {
        if(firstHalf->data!=temp->data)
            return false;

        firstHalf=firstHalf->next;
        temp=temp->next;
    }

    return true;
}

int main()
{
    vector<int> arr={1,2,3,2,1};

    Node* head=createLL(arr);

    print(head);

    if(isPalindrome(head))
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";

    return 0;
}