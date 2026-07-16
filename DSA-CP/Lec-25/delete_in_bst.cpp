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

Node* minValue(Node* root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int key)
{
    if(root == NULL)
        return NULL;

    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // 0 Child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 Left Child
        if(root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 1 Right Child
        if(root->left == NULL && root->right != NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 Children
        Node* temp = minValue(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;

    int arr[] = {50,30,70,20,40,60,80};

    for(int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    cout << "Before Deletion\n";
    inorder(root);

    root = deleteNode(root, 70);

    cout << "\nAfter Deletion\n";
    inorder(root);

    return 0;
}