#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isIdentical(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;

    if(root1 == NULL || root2 == NULL)
        return false;

    if(root1->data != root2->data)
        return false;

    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if(isIdentical(root1, root2))
        cout << "Trees are Identical";
    else
        cout << "Trees are Not Identical";

    return 0;
}