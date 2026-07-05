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

Node* firstNode(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            slow = head;

            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

int main()
{
    vector<int> arr = {10,20,30,40,50};

    Node* head = createLL(arr);

    // Create Cycle
    head->next->next->next->next->next = head->next;

    Node* ans = firstNode(head);

    if(ans)
        cout<<"Cycle Starts At Node = "<<ans->data;
    else
        cout<<"No Cycle";

    return 0;
}