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
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* buildTreePreorder()
{
    int data;

    cin>>data;

    if(data==-1)
        return NULL;

    Node* root=new Node(data);

    root->left=buildTreePreorder();

    root->right=buildTreePreorder();

    return root;
}

void preorder(Node* root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";

    preorder(root->left);

    preorder(root->right);
}

int main()
{
    cout<<"Enter Nodes in Preorder (-1 for NULL)\n";

    Node* root=buildTreePreorder();

    cout<<"\nPreorder Traversal\n";

    preorder(root);

    return 0;
}