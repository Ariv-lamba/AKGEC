#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &maze,int i,int j,string path)
{
    int n=maze.size();

    if(i<0 || j<0 || i>=n || j>=n)
        return;

    if(maze[i][j]==0)
        return;

    if(i==n-1 && j==n-1)
    {
        cout<<path<<endl;
        return;
    }

    maze[i][j]=0;

    solve(maze,i+1,j,path+"D");
    solve(maze,i,j-1,path+"L");
    solve(maze,i,j+1,path+"R");
    solve(maze,i-1,j,path+"U");

    maze[i][j]=1;
}

int main()
{
    vector<vector<int>> maze={
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    solve(maze,0,0,"");

    return 0;
}