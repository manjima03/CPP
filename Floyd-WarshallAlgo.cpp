#include<bits/stdc++.h>
using namespace std;

void fwAlgo(vector<vector<int>>& Graph,int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                Graph[i][j]=min(Graph[i][j],(Graph[i][k]==INT_MAX || Graph[k][j]==INT_MAX? INT_MAX:Graph[i][k]+Graph[k][j] ));
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<Graph[i][j]<<"    ";
        }
        cout<<endl;
    }
}

int main()
{
    int n=4;
    vector<vector<int>> Graph={
        {0,3,INT_MAX,7},
        {8,0,2,INT_MAX},
        {5,INT_MAX,0,1},
        {2,INT_MAX,INT_MAX,0}
    };

    fwAlgo(Graph,n);

    return 0;
}