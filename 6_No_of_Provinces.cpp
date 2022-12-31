// No of connected components problem

// DFS Approach
// No of times DFS is called on a node is equal to the no of connected components

#include<bits/stdc++.h>
using namespace std;


// Adjacency list approach
void dfs(int node, vector<int>adj[], int vis[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}

int dfsOnGraph(int V, vector<int>adj[]) {
    int vis[V] = {0};
    int count = 0;
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            count++;
            dfs(i,adj,vis);
        }
    }
    return count;
}

// Space complexity -> O(N)
// Time complexity -> O(N) + O(V+2*E)

// Matrix approach
// Approach 1 -> change the adj matrix to adj list and proceed as above
int numProvinces(vector<vector<int>> adj, int V){
    vector<int> adjLs[V];
    // To change adjacency matrix to list
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1 && i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    int vis[V] = {0};
    int cnt = 0;
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            cnt++;
            dfs(i,adjLs,vis);
        }
    }
    return cnt;
}
