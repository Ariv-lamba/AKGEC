#include <iostream>
using namespace std;

int solve(int row,int col,int m,int n)
{
    if(row==m-1 && col==n-1)
        return 1;

    if(row>=m || col>=n)
        return 0;

    int down=solve(row+1,col,m,n);

    int right=solve(row,col+1,m,n);

    return down+right;
}

int uniquePaths(int m,int n)
{
    return solve(0,0,m,n);
}

int pathsThroughFixedPoint(int m,int n,int x,int y)
{
    int path1=solve(0,0,x+1,y+1);

    int path2=solve(x,y,m,n);

    return path1*path2;
}

int main()
{
    int m=3;
    int n=3;

    int x=1;
    int y=1;

    cout<<"Total Paths = "
        <<pathsThroughFixedPoint(m,n,x,y);

    return 0;
}