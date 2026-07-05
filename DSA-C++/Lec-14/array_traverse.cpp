#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter Size: ";
    cin>>n;

    int arr[100];

    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Array Elements: ";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}