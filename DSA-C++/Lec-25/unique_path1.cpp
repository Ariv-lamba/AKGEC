#include<iostream>
using namespace std;

int solve(int row,int col,int m,int n)
{
    if(row==m-1 && col==n-1)
        return 1;

    if(row>=m || col>=n)
        return 0;

    // Down
    int down=solve(row+1,col,m,n);

    // Right
    int right=solve(row,col+1,m,n);

    return down+right;
}

int uniquePaths(int m,int n)
{
    return solve(0,0,m,n);
}

int main()
{
    int m=3;
    int n=3;

    cout<<"Total Paths = "<<uniquePaths(m,n);

    return 0;
}