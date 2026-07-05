#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[100];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Leaders: ";

    for(int i=0;i<n;i++) {

        bool leader=true;

        for(int j=i+1;j<n;j++) {
            if(arr[j]>arr[i]) {
                leader=false;
                break;
            }
        }

        if(leader)
            cout<<arr[i]<<" ";
    }

    return 0;
}