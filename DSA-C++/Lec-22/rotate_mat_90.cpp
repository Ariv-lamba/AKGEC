#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    // Transpose
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse every row
    for(int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(vector<vector<int>>& matrix)
{
    for(auto row : matrix)
    {
        for(int x : row)
            cout << x << " ";

        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout<<"Original Matrix"<<endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    cout<<"\nRotated Matrix"<<endl;
    printMatrix(matrix);

    return 0;
}