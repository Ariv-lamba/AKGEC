#include<iostream>
#include<vector>
#include<queue>
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

void markParents(Node* root, unordered_map<Node*, Node*>& parent)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->left)
        {
            parent[temp->left] = temp;
            q.push(temp->left);
        }

        if(temp->right)
        {
            parent[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

Node* findNode(Node* root, int target)
{
    if(root == NULL)
        return NULL;

    if(root->data == target)
        return root;

    Node* left = findNode(root->left, target);

    if(left)
        return left;

    return findNode(root->right, target);
}

vector<int> distanceK(Node* root, int target, int k)
{
    unordered_map<Node*, Node*> parent;
    markParents(root, parent);

    Node* targetNode = findNode(root, target);

    unordered_map<Node*, bool> visited;

    queue<Node*> q;
    q.push(targetNode);
    visited[targetNode] = true;

    int distance = 0;

    while(!q.empty())
    {
        int size = q.size();

        if(distance == k)
            break;

        distance++;

        while(size--)
        {
            Node* current = q.front();
            q.pop();

            if(current->left && !visited[current->left])
            {
                visited[current->left] = true;
                q.push(current->left);
            }

            if(current->right && !visited[current->right])
            {
                visited[current->right] = true;
                q.push(current->right);
            }

            if(parent[current] && !visited[parent[current]])
            {
                visited[parent[current]] = true;
                q.push(parent[current]);
            }
        }
    }

    vector<int> ans;

    while(!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
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

    int target = 2;
    int k = 2;

    vector<int> ans = distanceK(root, target, k);

    for(int x : ans)
        cout << x << " ";

    return 0;
}