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

Node* insertHead(Node *head, int x)
{
    Node *temp = new Node(x);

    temp->next = head;

    return temp;
}

Node* insertTail(Node *head, int x)
{
    Node *temp = new Node(x);

    if(head == NULL)
        return temp;

    Node *curr = head;

    while(curr->next != NULL)
        curr = curr->next;

    curr->next = temp;

    return head;
}

Node* insertPosition(Node *head, int pos, int x)
{
    Node *temp = new Node(x);

    if(pos == 1)
    {
        temp->next = head;
        return temp;
    }

    Node *curr = head;

    for(int i = 1; i < pos - 1 && curr != NULL; i++)
        curr = curr->next;

    if(curr == NULL)
        return head;

    temp->next = curr->next;
    curr->next = temp;

    return head;
}

int main()
{
    vector<int> arr = {10,20,30,40};

    Node *head = create(arr);

    cout << "Original : ";
    print(head);

    head = insertHead(head,5);

    cout << "After Insert Head : ";
    print(head);

    head = insertTail(head,50);

    cout << "After Insert Tail : ";
    print(head);

    head = insertPosition(head,3,100);

    cout << "After Insert Position : ";
    print(head);

    return 0;
}