#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node
{
public:

    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* createTree(vector<int> &arr)
{
    if(arr.size()==0 || arr[0]==-1)
        return NULL;

    Node *root=new Node(arr[0]);

    queue<Node*> q;

    q.push(root);

    int i=1;

    while(!q.empty() && i<arr.size())
    {
        Node *curr=q.front();
        q.pop();

        if(i<arr.size() && arr[i]!=-1)
        {
            curr->left=new Node(arr[i]);
            q.push(curr->left);
        }

        i++;

        if(i<arr.size() && arr[i]!=-1)
        {
            curr->right=new Node(arr[i]);
            q.push(curr->right);
        }

        i++;
    }

    return root;
}

void inorder(Node *root)
{
    if(root==NULL)
        return;

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}

int main()
{
    vector<int> arr={1,2,3,4,5,-1,6};

    Node *root=createTree(arr);

    inorder(root);

    return 0;
}