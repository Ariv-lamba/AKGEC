#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& weights, int days, int capacity)
{
    int day = 1;
    int load = 0;

    for(int i = 0; i < weights.size(); i++)
    {
        if(load + weights[i] <= capacity)
        {
            load += weights[i];
        }
        else
        {
            day++;
            load = weights[i];

            if(day > days)
                return false;
        }
    }

    return true;
}

int shipWithinDays(vector<int>& weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());

    int high = 0;

    for(int x : weights)
        high += x;

    int ans = high;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(isPossible(weights, days, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};

    int days = 5;

    cout << "Minimum Capacity = "
         << shipWithinDays(weights, days);

    return 0;
}