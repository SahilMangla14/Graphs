// If in kahn's algo if we get topo sort of n elements, then
// the given graph has no cycle else it has cycle

#include<bits/stdc++.h>
using namespace std;

// Topo Sort using Kahn's Algo (BFS)
// We will use indegree array which will store no. of incoming edge to a node

// Steps
// Insert all nodes with indegree 0
// Take them out of the queue
// Reduce the indegree of the adjacent nodes of the the node taken out of queue
// Whenever the indegree becomes 0, insert it in queue


bool isCyclic(int V, vector<int> adj[]){
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

    int cnt = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    if(cnt==V) return false;
    else return true;
}

// Time complexity -> same as bfs
// Space complexity -> same as bfs + indegree array


int main(){

    return 0;
}