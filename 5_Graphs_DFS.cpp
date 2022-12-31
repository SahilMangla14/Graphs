// DFS -> Depth first search
// Algorithm - Recursion

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>adj[], int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    // traverse all its neighbours
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0}; // visited array
    int start = 0; // start represents the starting node
    vector<int> ls; // store dfs traversal
    dfs(start, adj, vis, ls);
    return ls;
}


// Space complexity -   O(N)        +        O(N)      +      O(N)          = O(N)
//                    ( visited arr )    ( adj list)    ( stack space )

// Time complexity - O(N) + O(Sumation of degrees) = O(N) + O(2*E)  (For undirected graph)

