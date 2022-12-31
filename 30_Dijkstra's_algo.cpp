#include<bits/stdc++.h>
using namespace std;

// Dijkstra's algo work for both undirected and directed graphs but weight should be positve only
//Dijkstra's algorithm solves the shortest-path problem for any weighted, directed graph with non-negative weights. It can handle graphs consisting of cycles, but negative weights will cause this algorithm to produce incorrect results.


vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V);
    for(int i=0;i<V;++i) dist[i] = 1e9;

    dist[S] = 0;
    pq.push({0,S});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }

    return dist;
}

// Dijkstra does not works in negative weight
// TC - ElogV where E is total no of edges and V is total no of nodes

int main()
{

    return 0;
}