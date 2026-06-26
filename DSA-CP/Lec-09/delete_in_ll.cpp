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

Node* deleteHead(Node *head)
{
    if(head == NULL || head->next == NULL)
        return NULL;

    Node *curr = head;
    head = head->next;

    delete curr;

    return head;
}

Node* deleteTail(Node *head)
{
    if(head == NULL || head->next == NULL)
        return NULL;

    Node *curr = head;

    while(curr->next->next != NULL)
        curr = curr->next;

    delete curr->next;

    curr->next = NULL;

    return head;
}

Node* deletePosition(Node *head, int k)
{
    if(head == NULL)
        return NULL;

    if(k == 1)
    {
        Node *curr = head;
        head = head->next;

        delete curr;

        return head;
    }

    int count = 1;

    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL)
    {
        if(count == k)
        {
            prev->next = curr->next;

            delete curr;

            break;
        }

        prev = curr;
        curr = curr->next;
        count++;
    }

    return head;
}

int main()
{
    vector<int> arr = {10,20,30,40,50};

    Node *head = create(arr);

    cout << "Original : ";
    print(head);

    head = deleteHead(head);

    cout << "After Delete Head : ";
    print(head);

    head = deleteTail(head);

    cout << "After Delete Tail : ";
    print(head);

    head = deletePosition(head,2);

    cout << "After Delete Position : ";
    print(head);

    return 0;
}