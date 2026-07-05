#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int zeroCount = 0;
    long long product = 1;

    // Count zeros and calculate product of non-zero elements
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            zeroCount++;
        else
            product *= arr[i];
    }

    // Case 1: More than one zero
    if(zeroCount > 1)
    {
        for(int i = 0; i < n; i++)
            cout << 0 << " ";
    }

    // Case 2: Exactly one zero
    else if(zeroCount == 1)
    {
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 0)
                cout << product << " ";
            else
                cout << 0 << " ";
        }
    }

    // Case 3: No zero
    else
    {
        for(int i = 0; i < n; i++)
            cout << product / arr[i] << " ";
    }

    return 0;
}