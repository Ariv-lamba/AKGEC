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

int sumOfLeftLeaves(Node* root)
{
    if(root == NULL)
        return 0;

    int sum = 0;

    if(root->left &&
       root->left->left == NULL &&
       root->left->right == NULL)
    {
        sum += root->left->data;
    }

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main()
{
    Node* root = new Node(3);

    root->left = new Node(9);
    root->right = new Node(20);

    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Sum = " << sumOfLeftLeaves(root);

    return 0;
}