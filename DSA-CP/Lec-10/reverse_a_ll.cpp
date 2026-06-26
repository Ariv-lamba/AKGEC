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

int main()
{
    vector<int> arr = {10,20,30,40,50};
    Node *head = create(arr);
    cout << "Original List : ";
    print(head);
    head = reverse(head);
    cout << "Reversed List : ";
    print(head);
    return 0;
}