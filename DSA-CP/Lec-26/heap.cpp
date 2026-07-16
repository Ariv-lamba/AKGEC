#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int largest=i;

    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest])
        largest=left;

    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);

        heapify(arr,n,largest);
    }
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

int main()
{
    int arr[]={50,55,53,52,54};

    int n=5;

    cout<<"Before Heapify"<<endl;
    print(arr,n);

    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    cout<<"\nAfter Heapify"<<endl;
    print(arr,n);

    return 0;
}