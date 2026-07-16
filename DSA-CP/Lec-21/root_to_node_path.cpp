#include<iostream>
#include<vector>
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

bool getPath(Node* root, int target, vector<int>& path)
{
    if(root == NULL)
        return false;

    path.push_back(root->data);

    if(root->data == target)
        return true;

    if(getPath(root->left, target, path) ||
       getPath(root->right, target, path))
        return true;

    path.pop_back();

    return false;
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

    int target = 5;

    vector<int> path;

    if(getPath(root, target, path))
    {
        for(int x : path)
            cout << x << " ";
    }
    else
    {
        cout << "Node Not Found";
    }

    return 0;
}