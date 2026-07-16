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

int countNodes(Node* root)
{
    if(root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node* root, int index, int totalNodes)
{
    if(root == NULL)
        return true;

    if(index >= totalNodes)
        return false;

    bool left = isCBT(root->left, 2 * index + 1, totalNodes);
    bool right = isCBT(root->right, 2 * index + 2, totalNodes);

    return left && right;
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);

    int totalNodes = countNodes(root);

    if(isCBT(root, 0, totalNodes))
        cout << "Complete Binary Tree";
    else
        cout << "Not a Complete Binary Tree";

    return 0;
}