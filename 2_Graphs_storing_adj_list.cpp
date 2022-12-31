#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1]; // Adjacency list

    // For undirected graph -> Space complexity = O(2*e)
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // For directed graph -> Space complexity = O(e)
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    // }

    // For weighted graphs, We will store pairs
    // for eg. if 4 has edge with 2 with weight 1 and 4 also has edge with 3 with weight 3, we will store it like -> 4 -> {{2,1},{3,4}}
    // vector<pair<int,int>> adj[n+1];
    // for(int i=0;i<m;i++){
    //     int u,v,w;
    //     cin >> u >> v >> w;
    //     adj[u].push_back({v,w});
    //     adj[v].push_back({u,w});
    // }

}