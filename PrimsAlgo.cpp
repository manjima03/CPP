#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> pii;

void prims(vector<vector<pii>>& graph, int n)
{
    vector<bool> inMST(n,false);
    vector<int> key(n, __INT_MAX__);
    vector<int> parent(n,-1);

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        int u=pq.top().second; 
        
        pq.pop();

        
        if(inMST[u]) continue;
        inMST[u]=true;

        for(auto& neighbour : graph[u])
        {
            int v=neighbour.second;
            int weight=neighbour.first;
            if(!inMST[v] && weight<key[v])
            {
                key[v]=weight;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }

    }

    cout<<"The MST is : "<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<"--->"<<i<<"  "<<key[i]<<endl;
    }

}

int main()
{
    int n=5;
    vector<vector<pii>> graph(n);
    graph[0].push_back({2,1});
    graph[1].push_back({2,0});
    
    graph[0].push_back({6,3});
    graph[3].push_back({6,0});
    
    graph[1].push_back({3,2});
    graph[2].push_back({3,1});
    
    graph[1].push_back({8,3});
    graph[3].push_back({8,1});
    
    graph[1].push_back({5,4});
    graph[4].push_back({5,1});
    
    graph[2].push_back({7,4});
    graph[4].push_back({7,2});

    graph[3].push_back({9,4});
    graph[4].push_back({9,3});

    prims(graph,n);
    return 0;
}