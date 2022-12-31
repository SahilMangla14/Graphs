#include<bits/stdc++.h>
using namespace std;

// bipartite graphs also used for odd length cycle detection

bool dfs(int node,int col, int V, vector<int> adj[], int color[]){
    color[node] = col;
    for(int x:adj[node]){
        if(color[x]==-1){
            if(dfs(x,!col,V,adj,color)==false) return false;
        }
        else if(color[x]==color[node]){
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[]){
    int color[V];
    for(int i=0;i<V;i++){
        color[i] = -1;
    }

    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(dfs(i,0,V,adj,color)==false) return false;
        }
    }

    return true;
}

// TC -> Same as DFS
// SC -> Same as DFS

int main() {

    return 0;
}