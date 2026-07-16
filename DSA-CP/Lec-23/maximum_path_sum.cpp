#include<iostream>
#include<climits>
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

int solve(Node* root, int &ans)
{
    if(root == NULL)
        return 0;

    int left = max(0, solve(root->left, ans));
    int right = max(0, solve(root->right, ans));

    ans = max(ans, left + right + root->data);

    return root->data + max(left, right);
}

int maxPathSum(Node* root)
{
    int ans = INT_MIN;

    solve(root, ans);

    return ans;
}

int main()
{
    Node* root = new Node(-10);

    root->left = new Node(9);

    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Maximum Path Sum = "
         << maxPathSum(root);

    return 0;
}