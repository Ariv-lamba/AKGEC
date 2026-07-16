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

Node* LCA(Node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    Node* leftAns = LCA(root->left, n1, n2);
    Node* rightAns = LCA(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL)
        return root;

    if(leftAns != NULL)
        return leftAns;

    return rightAns;
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int node1 = 4;
    int node2 = 5;

    Node* ans = LCA(root, node1, node2);

    if(ans)
        cout << "LCA = " << ans->data;
    else
        cout << "Node Not Found";

    return 0;
}