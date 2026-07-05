#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> prefix(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    prefix[0] = arr[0];

    for(int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    for(int x : prefix)
        cout << x << " ";

    return 0;
}