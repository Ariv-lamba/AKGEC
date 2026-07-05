#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout<<"Enter Size: ";
    cin>>n;

    vector<int> v(n);

    cout<<"Enter Elements: ";

    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<"Vector Elements: ";

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";

    return 0;
}