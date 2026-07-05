#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> suffix(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    suffix[n - 1] = arr[n - 1];

    for(int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + arr[i];

    for(int x : suffix)
        cout << x << " ";

    return 0;
}