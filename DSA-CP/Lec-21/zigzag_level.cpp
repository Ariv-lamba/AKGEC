#include<iostream>
#include<vector>
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

vector<int> zigZagTraversal(Node* root)
{
    vector<int> ans;

    if(root == NULL)
        return ans;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty())
    {
        int size = q.size();

        vector<int> temp(size);

        for(int i = 0; i < size; i++)
        {
            Node* front = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;

            temp[index] = front->data;

            if(front->left)
                q.push(front->left);

            if(front->right)
                q.push(front->right);
        }

        leftToRight = !leftToRight;

        for(int x : temp)
            ans.push_back(x);
    }

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

    vector<int> ans = zigZagTraversal(root);

    for(int x : ans)
        cout << x << " ";

    return 0;
}