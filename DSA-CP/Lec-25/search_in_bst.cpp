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

Node* insert(Node* root, int val)
{
    if(root == NULL)
        return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

bool search(Node* root, int key)
{
    if(root == NULL)
        return false;

    if(root->data == key)
        return true;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main()
{
    Node* root = NULL;

    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,70);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,60);
    root = insert(root,80);

    int key = 60;

    if(search(root,key))
        cout<<"Found";
    else
        cout<<"Not Found";

    return 0;
}