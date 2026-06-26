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
        data = x;
        next = NULL;
    }
};

Node* create(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *curr = head;

    for(int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }

    return head;
}

void print(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

void removeCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            slow = head;

            if(slow == fast)
            {
                while(fast->next != slow)
                    fast = fast->next;

                fast->next = NULL;
                return;
            }

            while(slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
            return;
        }
    }
}

int main()
{
    vector<int> arr = {10,20,30,40,50};
    Node *head = create(arr);
    Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head->next;
    removeCycle(head);
    print(head);
    return 0;
}