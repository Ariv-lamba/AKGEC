#include<iostream>
#include<queue>
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

Node* buildTreeLevelOrder()
{
    int data;

    cout<<"Enter Root Value : ";
    cin>>data;

    if(data==-1)
        return NULL;

    Node* root=new Node(data);

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        int leftData,rightData;

        cout<<"Enter Left Child of "<<temp->data<<" : ";
        cin>>leftData;

        if(leftData!=-1)
        {
            temp->left=new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter Right Child of "<<temp->data<<" : ";
        cin>>rightData;

        if(rightData!=-1)
        {
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }

    return root;
}

void levelOrder(Node* root)
{
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}

int main()
{
    Node* root=buildTreeLevelOrder();

    cout<<"\nLevel Order Traversal\n";

    levelOrder(root);

    return 0;
}