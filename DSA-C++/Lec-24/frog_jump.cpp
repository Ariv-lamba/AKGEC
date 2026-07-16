#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int solve(vector<int>& height,int index)
{
    if(index==height.size()-1)
        return 0;

    int jumpOne=abs(height[index]-height[index+1])+
                solve(height,index+1);

    int jumpTwo=INT_MAX;

    if(index+2<height.size())
    {
        jumpTwo=abs(height[index]-height[index+2])+
                solve(height,index+2);
    }

    return min(jumpOne,jumpTwo);
}

int frogJump(vector<int>& height)
{
    return solve(height,0);
}

int main()
{
    vector<int> height={10,20,30,10};

    cout<<"Minimum Cost = "<<frogJump(height);

    return 0;
}