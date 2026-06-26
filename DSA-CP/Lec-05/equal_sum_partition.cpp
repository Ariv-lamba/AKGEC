#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr,int i,int s1,int s2,
           vector<int> &a,
           vector<int> &b)
{
    if(i==arr.size())
    {
        if(s1==s2)
        {
            cout<<"A : ";

            for(int x:a)
                cout<<x<<" ";

            cout<<"    B : ";

            for(int x:b)
                cout<<x<<" ";

            cout<<endl;
        }

        return;
    }

    a.push_back(arr[i]);

    solve(arr,i+1,s1+arr[i],s2,a,b);

    a.pop_back();

    b.push_back(arr[i]);

    solve(arr,i+1,s1,s2+arr[i],a,b);

    b.pop_back();
}

int main()
{
    vector<int> arr={1,5,11,5};

    vector<int> a,b;

    solve(arr,0,0,0,a,b);
}