#include<iostream>
using namespace std;

void printHello(int n)
{
    if(n == 0)
        return;

    cout<<"Hello"<<endl;

    printHello(n - 1);
}

int main()
{
    int n = 5;

    printHello(n);

    return 0;
}