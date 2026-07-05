#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
public:

    class Node{
    public:
        int key,value;
        Node *prev,*next;

        Node(int k,int v)
        {
            key=k;
            value=v;
            prev=NULL;
            next=NULL;
        }
    };

    unordered_map<int,Node*> mp;

    Node *head;
    Node *tail;

    int cap;

    LRUCache(int capacity)
    {
        cap=capacity;

        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
    }

    void remove(Node *node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void insert(Node *node)
    {
        node->next=head->next;

        node->prev=head;

        head->next->prev=node;

        head->next=node;
    }

    int get(int key)
    {
        if(mp.find(key)==mp.end())
            return -1;

        Node *node=mp[key];

        remove(node);

        insert(node);

        return node->value;
    }

    void put(int key,int value)
    {
        if(mp.find(key)!=mp.end())
        {
            Node *node=mp[key];

            remove(node);

            node->value=value;

            insert(node);

            return;
        }

        if(mp.size()==cap)
        {
            Node *node=tail->prev;

            remove(node);

            mp.erase(node->key);
        }

        Node *node=new Node(key,value);

        insert(node);

        mp[key]=node;
    }
};
int main()
{
    LRUCache cache(2);

    cache.put(1,10);
    cache.put(2,20);

    cout<<"get(1) = "<<cache.get(1)<<endl;

    cache.put(3,30);

    cout<<"get(2) = "<<cache.get(2)<<endl;

    cache.put(4,40);

    cout<<"get(1) = "<<cache.get(1)<<endl;
    cout<<"get(3) = "<<cache.get(3)<<endl;
    cout<<"get(4) = "<<cache.get(4)<<endl;

    return 0;
}