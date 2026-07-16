#include<iostream>
#include<algorithm>
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

int solve(Node* root,int &diameter)
{
    if(root==NULL)
        return 0;

    int leftHeight=solve(root->left,diameter);

    int rightHeight=solve(root->right,diameter);

    diameter=max(diameter,leftHeight+rightHeight);

    return max(leftHeight,rightHeight)+1;
}

int diameterOfTree(Node* root)
{
    int diameter=0;

    solve(root,diameter);

    return diameter;
}

int main()
{
    Node* root=new Node(1);

    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->right=new Node(6);
    root->right->right->right=new Node(7);

    cout<<"Diameter = "<<diameterOfTree(root);

    return 0;
}