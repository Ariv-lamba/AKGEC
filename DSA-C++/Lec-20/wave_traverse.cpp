#include<iostream>
#include<vector>
using namespace std;

vector<int> waveTraversal(vector<vector<int>>& matrix)
{
    vector<int> ans;

    int row = matrix.size();
    int col = matrix[0].size();

    for(int j=0;j<col;j++)
    {
        if(j%2==0)
        {
            for(int i=0;i<row;i++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        else
        {
            for(int i=row-1;i>=0;i--)
            {
                ans.push_back(matrix[i][j]);
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> ans = waveTraversal(matrix);

    for(int x : ans)
        cout<<x<<" ";

    return 0;
}