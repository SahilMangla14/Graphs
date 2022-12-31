// This algo will help to find shortest distance with negative values as well / helps to detect negative cycles
// The bellman word algo will work only on directed graphs
// So, for undirected graph  we need to consider edge both ways with same weight

// If path weight is less than 0, we call it as negative cycle

// relax all the edges n-1 times sequentially
// Relax definition -> if(dist[u]+wt < dist[v]){ dis[v] = dist[u]+wt}

// Why N-1?
// Ans -> Since in a graph of N nodes, in worst case, you will take N-1 edges to reach from the first to the last, thereby we iterate for N-1 iterations
// Try drawing a graph which takes more than N-1 edges for any path, it is not possible

// How to detect negative cycle?
// Since we have proved that afte N-1 iterations, we will have shortest distance, but if after N-1 iterations i.e. at the Nth iteration if we
// still get the shorter path that means it has negative cycle


#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>&edges, int S){
    vector<int> dist(V,1e8);
    dist[S] = 0;

    for(int i=0;i<V-1;i++){
        for(auto it:edges){
            int u = it[0]; 
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e8 && dist[u]+wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    // nth relaxation to check negative cycle
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u]!=1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    
    return dist;
}

// Time complexity -> O(V*E)