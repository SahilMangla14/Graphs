#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    // graph here
    int adj[n+1][m+1]; // for 1-based indexing
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

 
    // For weighted Graph
    // If the weight of edge between u and v is w, we will store w in place of 1
    // for(int i=0;i<m;i++){
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     adj[u][v] = w;
    //     adj[v][u] = w;
    // }

    // If we have directed graph, we have to make edge from u to v only
    
    return 0;
}

