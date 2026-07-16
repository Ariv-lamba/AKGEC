#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int lastStoneWeight(vector<int>& stones)
{
    priority_queue<int> pq;

    for(int stone : stones)
        pq.push(stone);

    while(pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        if(first != second)
            pq.push(first - second);
    }

    if(pq.empty())
        return 0;

    return pq.top();
}

int main()
{
    vector<int> stones = {2,7,4,1,8,1};

    cout << "Last Stone Weight = "
         << lastStoneWeight(stones);

    return 0;
}