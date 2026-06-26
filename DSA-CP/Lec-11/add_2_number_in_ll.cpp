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

Node* addTwoNumbers(Node *head1, Node *head2)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;

    int carry = 0;

    while(head1 != NULL || head2 != NULL || carry != 0)
    {
        int sum = carry;

        if(head1 != NULL)
        {
            sum = sum + head1->data;
            head1 = head1->next;
        }

        if(head2 != NULL)
        {
            sum = sum + head2->data;
            head2 = head2->next;
        }

        carry = sum / 10;

        Node *newNode = new Node(sum % 10);

        temp->next = newNode;

        temp = temp->next;
    }

    return dummy->next;
}

int main()
{
    Node *head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    Node *head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    cout << "List 1 : ";
    print(head1);

    cout << "List 2 : ";
    print(head2);

    Node *ans = addTwoNumbers(head1, head2);
    cout << "Answer : ";
    print(ans);
    return 0;
}