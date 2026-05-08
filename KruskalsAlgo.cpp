#include<bits/stdc++.h>
using namespace std;


int n=4;
vector<int> parent(n+1,-1);

struct Edge
{
    int u,v,cost;
};

int find(int a)
{
    while(parent[a]!=-1)
    {
        a=parent[a];
    }
    return a;
}

void Union(int j,int k)
{
    parent[j]=k;
}

void kruskalsAlgo(vector<Edge>& edges)
{
    int m=edges.size();
    sort(edges.begin(),edges.end(), [](Edge a, Edge b){
        return a.cost<b.cost;
    });
    int mincost=0;
    int count=0;
    for(int i=0;i<m && count<n-1;i++)
    {
        int j=find(edges[i].u);
        int k=find(edges[i].v);

        if(j!=k)
        {
            count++;
            mincost+=edges[i].cost;
            cout<<edges[i].u<<"----"<<edges[i].v<<endl;
            Union(j,k);
        }
    }
    cout<<"Minimum cost= "<<mincost;
}

int main()
{
    
    vector<Edge> edges(n);
    edges={
        {1,2,10},
        {1,4,5},
        {2,4,15},
        {1,3,6},
        {3,4,4}
    };
    kruskalsAlgo(edges);
    return 0;

}