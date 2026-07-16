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

bool getPath(Node* root, int target, vector<Node*>& path)
{
    if(root == NULL)
        return false;

    path.push_back(root);

    if(root->data == target)
        return true;

    if(getPath(root->left, target, path) ||
       getPath(root->right, target, path))
        return true;

    path.pop_back();

    return false;
}

Node* LCA(Node* root, int n1, int n2)
{
    vector<Node*> path1;
    vector<Node*> path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2))
        return NULL;

    int i = 0;

    while(i < path1.size() &&
          i < path2.size() &&
          path1[i] == path2[i])
    {
        i++;
    }

    return path1[i - 1];
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