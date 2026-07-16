#include<iostream>
#include<vector>
#include<unordered_map>
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

Node* solve(vector<int>& postorder,
            vector<int>& inorder,
            int& postIndex,
            int inStart,
            int inEnd,
            unordered_map<int,int>& mp)
{
    if(postIndex < 0 || inStart > inEnd)
        return NULL;

    int element = postorder[postIndex--];
    Node* root = new Node(element);

    int position = mp[element];

    root->right = solve(postorder, inorder, postIndex,
                        position + 1, inEnd, mp);

    root->left = solve(postorder, inorder, postIndex,
                       inStart, position - 1, mp);

    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    unordered_map<int,int> mp;

    for(int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;

    int postIndex = postorder.size() - 1;

    return solve(postorder, inorder, postIndex,
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
    vector<int> inorder   = {4,2,5,1,6,3,7};
    vector<int> postorder = {4,5,2,6,7,3,1};

    Node* root = buildTree(inorder, postorder);

    levelOrder(root);

    return 0;
}