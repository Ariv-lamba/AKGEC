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

Node* merge(Node *head1, Node *head2)
{
    Node *dummy = new Node(0);

    Node *temp = dummy;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }

        temp = temp->next;
    }

    if(head1 != NULL)
        temp->next = head1;

    if(head2 != NULL)
        temp->next = head2;

    return dummy->next;
}

int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    cout << "List 1 : ";
    print(head1);

    cout << "List 2 : ";
    print(head2);

    Node *head = merge(head1, head2);

    cout << "Merged List : ";
    print(head);

    return 0;
}