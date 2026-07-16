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

Node* insert(Node* root,int val)
{
    if(root==NULL)
        return new Node(val);

    if(val<root->data)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);

    return root;
}

Node* LCA(Node* root,int p,int q)
{
    if(root==NULL)
        return NULL;

    if(p<root->data && q<root->data)
        return LCA(root->left,p,q);

    if(p>root->data && q>root->data)
        return LCA(root->right,p,q);

    return root;
}

int main()
{
    Node* root=NULL;

    int arr[]={50,30,70,20,40,60,80};

    for(int i=0;i<7;i++)
        root=insert(root,arr[i]);

    Node* ans=LCA(root,20,40);

    cout<<"LCA = "<<ans->data;

    return 0;
}