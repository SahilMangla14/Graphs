#include<bits/stdc++.h>
using namespace std;

// Topo Sort using Kahn's Algo (BFS)
// We will use indegree array which will store no. of incoming edge to a node

// Steps
// Insert all nodes with indegree 0
// Take them out of the queue
// Reduce the indegree of the adjacent nodes of the the node taken out of queue
// Whenever the indegree becomes 0, insert it in queue



// kahn's algo will also work for disconnected graphs
// many applications
// topo sort
// cycle detection in directed graphs
// finding eventual safe states
// course schedule problem

vector<int> topoSort(int V, vector<int> adj[]){
    int indegree[V] = {0};
    for(int i=0;i<V;++i){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    return topo;
}

// Time complexity -> same as bfs
// Space complexity -> same as bfs + indegree array


int main(){

    return 0;
}