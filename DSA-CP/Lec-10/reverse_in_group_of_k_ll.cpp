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

Node* reverseK(Node *head, int k)
{
    if(head == NULL)
        return NULL;

    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    int count = 0;

    while(curr != NULL && count < k)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;

        count++;
    }

    if(next != NULL)
        head->next = reverseK(next, k);

    return prev;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8};

    Node *head = create(arr);

    cout << "Original List : ";
    print(head);

    int k;

    cout << "Enter k : ";
    cin >> k;

    head = reverseK(head, k);

    cout << "After Reverse : ";
    print(head);

    return 0;
}