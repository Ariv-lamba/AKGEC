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

void solve(Node* root,int &k,int &ans)
{
    if(root==NULL)
        return;

    solve(root->left,k,ans);

    k--;

    if(k==0)
    {
        ans=root->data;
        return;
    }

    solve(root->right,k,ans);
}

int kthSmallest(Node* root,int k)
{
    int ans=-1;

    solve(root,k,ans);

    return ans;
}

int main()
{
    Node* root=NULL;

    int arr[]={50,30,70,20,40,60,80};

    for(int i=0;i<7;i++)
        root=insert(root,arr[i]);

    int k=3;

    cout<<"Kth Smallest = "<<kthSmallest(root,k);

    return 0;
}