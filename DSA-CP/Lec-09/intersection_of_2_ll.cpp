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

Node* intersection(Node *head1, Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;

    while(p1 != p2)
    {
        if(p1 == NULL)
            p1 = head2;
        else
            p1 = p1->next;

        if(p2 == NULL)
            p2 = head1;
        else
            p2 = p2->next;
    }

    return p1;
}

int main()
{
    Node *common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);

    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = common;

    Node *head2 = new Node(15);
    head2->next = common;

    cout << "List 1 : ";
    print(head1);

    cout << "List 2 : ";
    print(head2);

    Node *ans = intersection(head1, head2);

    if(ans != NULL)
        cout << "Intersection Node = " << ans->data;
    else
        cout << "No Intersection";

    return 0;
}