#include<bits/stdc++.h>
using namespace std;

// Topo Sort -> Linear ordering of vertices such that if there is an edge between u and v, u appears before v in that ordering
// It exists only in DAG


void dfs(int node, vector<int>adj[], int vis[],stack<int> &st){
    vis[node] = 1;
    
    // traverse all its neighbours
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }

    st.push(node);
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int vis[V]; // visited array
    stack<int> st;

    // If the graph is disconnected, we need to call like below to push other components in stack
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    vector<int> ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

// Time Complexity -> same as DFS
// Space Complexity -> same as DFS + stack space

int main(){

    return 0;
}