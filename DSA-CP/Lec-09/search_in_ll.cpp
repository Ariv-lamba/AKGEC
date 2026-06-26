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

bool search(Node *head, int x)
{
    while(head != NULL)
    {
        if(head->data == x)
            return true;

        head = head->next;
    }

    return false;
}

int main()
{
    vector<int> arr = {10,20,30,40,50};

    Node *head = create(arr);

    print(head);

    int x;

    cout << "Enter element to search : ";
    cin >> x;

    if(search(head, x))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}