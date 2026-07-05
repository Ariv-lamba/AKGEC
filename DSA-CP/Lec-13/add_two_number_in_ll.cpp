#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Create Linked List using Vector
Node* createLL(vector<int> &arr)
{
    if(arr.size()==0)
        return NULL;

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for(int i=1;i<arr.size();i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print Linked List
void print(Node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

// Add Two Numbers
Node* addTwoNumbers(Node *head1, Node *head2)
{
    Node *dummy = new Node(-1);
    Node *tail = dummy;

    int carry = 0;

    while(head1 || head2 || carry)
    {
        int sum = carry;

        if(head1)
        {
            sum += head1->data;
            head1 = head1->next;
        }

        if(head2)
        {
            sum += head2->data;
            head2 = head2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        tail->next = new Node(digit);
        tail = tail->next;
    }

    return dummy->next;
}

int main()
{
    vector<int> arr1 = {2,4,3};
    vector<int> arr2 = {5,6,4};

    Node *head1 = createLL(arr1);
    Node *head2 = createLL(arr2);

    cout<<"First Number : ";
    print(head1);

    cout<<"Second Number : ";
    print(head2);

    Node *ans = addTwoNumbers(head1, head2);

    cout<<"Answer : ";
    print(ans);

    return 0;
}