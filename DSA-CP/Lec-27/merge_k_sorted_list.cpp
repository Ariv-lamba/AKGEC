#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val=x;
        next=NULL;
    }
};

class Compare
{
public:
    bool operator()(ListNode* a,ListNode* b)
    {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<ListNode*,vector<ListNode*>,Compare> pq;

    for(int i=0;i<lists.size();i++)
    {
        if(lists[i])
            pq.push(lists[i]);
    }

    ListNode* dummy=new ListNode(-1);
    ListNode* tail=dummy;

    while(!pq.empty())
    {
        ListNode* temp=pq.top();
        pq.pop();

        tail->next=temp;
        tail=tail->next;

        if(temp->next)
            pq.push(temp->next);
    }

    return dummy->next;
}

void print(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main()
{
    ListNode* a=new ListNode(1);
    a->next=new ListNode(4);
    a->next->next=new ListNode(5);

    ListNode* b=new ListNode(1);
    b->next=new ListNode(3);
    b->next->next=new ListNode(4);

    ListNode* c=new ListNode(2);
    c->next=new ListNode(6);

    vector<ListNode*> lists;

    lists.push_back(a);
    lists.push_back(b);
    lists.push_back(c);

    ListNode* head=mergeKLists(lists);

    print(head);

    return 0;
}