#include <iostream>
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

void print(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

void deleteNode(Node *node)
{
    node->data = node->next->data;

    Node *temp = node->next;

    node->next = node->next->next;

    delete temp;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Original List : ";
    print(head);

    deleteNode(head->next->next);

    cout << "After Delete : ";
    print(head);

    return 0;
}