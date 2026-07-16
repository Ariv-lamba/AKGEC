#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>>& grid,int row,int col)
{
    int m=grid.size();
    int n=grid[0].size();

    // Out of Boundary
    if(row>=m || col>=n)
        return 0;

    // Obstacle
    if(grid[row][col]==1)
        return 0;

    // Destination
    if(row==m-1 && col==n-1)
        return 1;

    // Down
    int down=solve(grid,row+1,col);

    // Right
    int right=solve(grid,row,col+1);

    return down+right;
}

int uniquePathsWithObstacles(vector<vector<int>>& grid)
{
    return solve(grid,0,0);
}

int main()
{
    vector<vector<int>> grid={
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    cout<<"Total Paths = "
        <<uniquePathsWithObstacles(grid);

    return 0;
}