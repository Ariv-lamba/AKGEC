#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans;

    int maxi = arr[n - 1];
    ans.push_back(maxi);

    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] >= maxi) {
            maxi = arr[i];
            ans.push_back(arr[i]);
        }
    }

    reverse(ans.begin(), ans.end());

    for(int x : ans)
        cout << x << " ";

    return 0;
}