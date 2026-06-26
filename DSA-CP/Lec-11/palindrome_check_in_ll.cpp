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

Node* reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while(curr != NULL)
    {
        Node *next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;
    }

    return prev;
}

bool palindrome(Node *head)
{
    if(head == NULL || head->next == NULL)
        return true;

    Node *slow = head;
    Node *fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *second = reverse(slow->next);
    Node *first = head;
    while(second != NULL)
    {
        if(first->data != second->data)
            return false;

        first = first->next;
        second = second->next;
    }
    return true;
}

int main()
{
    vector<int> arr = {1,2,3,2,1};
    Node *head = create(arr);
    print(head);
    if(palindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
    return 0;
}