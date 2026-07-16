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

void solve(Node* root, int level, vector<int>& ans)
{
    if(root == NULL)
        return;

    if(level == ans.size())
        ans.push_back(root->data);

    solve(root->left, level + 1, ans);
    solve(root->right, level + 1, ans);
}

vector<int> leftView(Node* root)
{
    vector<int> ans;

    solve(root, 0, ans);

    return ans;
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

    vector<int> ans = leftView(root);

    for(int x : ans)
        cout << x << " ";

    return 0;
}