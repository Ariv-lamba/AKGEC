#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;

    Node(int d,int r,int c)
    {
        data=d;
        row=r;
        col=c;
    }
};

class Compare
{
public:
    bool operator()(Node* a,Node* b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arr)
{
    priority_queue<Node*,vector<Node*>,Compare> pq;

    for(int i=0;i<arr.size();i++)
    {
        pq.push(new Node(arr[i][0],i,0));
    }

    vector<int> ans;

    while(!pq.empty())
    {
        Node* temp=pq.top();
        pq.pop();

        ans.push_back(temp->data);

        int row=temp->row;
        int col=temp->col;

        if(col+1 < arr[row].size())
        {
            pq.push(new Node(arr[row][col+1],row,col+1));
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr=
    {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    vector<int> ans=mergeKSortedArrays(arr);

    for(int x:ans)
        cout<<x<<" ";

    return 0;
}