#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();

    vector<int> row(m,0);
    vector<int> col(n,0);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(row[i] || col[j])
                matrix[i][j]=0;
        }
    }
}

void print(vector<vector<int>>& matrix)
{
    for(auto row:matrix)
    {
        for(int x:row)
            cout<<x<<" ";

        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> matrix={
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    setZeroes(matrix);

    print(matrix);

    return 0;
}