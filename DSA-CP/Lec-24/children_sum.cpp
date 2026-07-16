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

bool isChildrenSum(Node* root)
{
    if(root == NULL)
        return true;

    if(root->left == NULL && root->right == NULL)
        return true;

    int left = 0;
    int right = 0;

    if(root->left)
        left = root->left->data;

    if(root->right)
        right = root->right->data;

    return (root->data == left + right) &&
           isChildrenSum(root->left) &&
           isChildrenSum(root->right);
}

int main()
{
    Node* root = new Node(10);

    root->left = new Node(8);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(5);

    root->right->right = new Node(2);

    if(isChildrenSum(root))
        cout<<"Children Sum Property Satisfied";
    else
        cout<<"Children Sum Property Not Satisfied";

    return 0;
}