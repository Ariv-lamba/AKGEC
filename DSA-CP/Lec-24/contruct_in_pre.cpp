#include<iostream>
#include<vector>
#include<unordered_map>
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

Node* solve(vector<int>& preorder,
            vector<int>& inorder,
            int& preIndex,
            int inStart,
            int inEnd,
            unordered_map<int,int>& mp)
{
    if(preIndex >= preorder.size() || inStart > inEnd)
        return NULL;

    int element = preorder[preIndex++];
    Node* root = new Node(element);

    int position = mp[element];

    root->left = solve(preorder, inorder, preIndex,
                       inStart, position - 1, mp);

    root->right = solve(preorder, inorder, preIndex,
                        position + 1, inEnd, mp);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    unordered_map<int,int> mp;

    for(int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;

    int preIndex = 0;

    return solve(preorder, inorder, preIndex,
                 0, inorder.size() - 1, mp);
}

void levelOrder(Node* root)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}

int main()
{
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> inorder  = {4,2,5,1,6,3,7};

    Node* root = buildTree(preorder, inorder);

    levelOrder(root);

    return 0;
}