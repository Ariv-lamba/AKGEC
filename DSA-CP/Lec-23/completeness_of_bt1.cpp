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

bool isCompleteBT(Node* root)
{
    if(root == NULL)
        return true;

    queue<Node*> q;
    q.push(root);

    bool foundNull = false;

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            foundNull = true;
        }
        else
        {
            if(foundNull)
                return false;

            q.push(temp->left);
            q.push(temp->right);
        }
    }

    return true;
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);

    if(isCompleteBT(root))
        cout << "Complete Binary Tree";
    else
        cout << "Not a Complete Binary Tree";

    return 0;
}