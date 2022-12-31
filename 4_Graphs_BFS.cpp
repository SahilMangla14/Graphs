// BFS -> Breadth First Search
// Level wise traversal
// For level order traversal, we will use queue data structure
// Traversal output's order varies as our node at 0 level changes

// adjacency list will store the neighbours

// So, if we are at a particular node, then the list of this node will contain all its neighbour or in other words, next level and
// previous level nodes. But then we visit next level nodes as we have already visited previous level and that is already marked in visited array

#include<bits/stdc++.h>
using namespace std;

// using adjacency list
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

// using adjacency matrix

vector<int> bfsUsingMatrix(int V, vector<vector<int>> adj){

    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i] == 1 && !vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }

    return bfs;
}

int main(){

    return 0;
}

// Space complexity = O(3*n) = O(n)
// Time complexity = O(N) + O(2*E) 
// E -> no of edges


