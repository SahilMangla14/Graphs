// BIPARTITE GRAPH -> color the graph with 2 colors such that no adjacent nodes have same color

// Some observations
// Linear graphs with no cycle are always bi-partite
// Any graph with even cycle length is bi-partite
// Any graph with odd length cycle can never by bi-partite

// Here, our visited array will represent whether our node is coloured or not
// 0 and 1 are two colours that we are assigning

#include<bits/stdc++.h>
using namespace std;

bool check(int start, int V, vector<int> adj[], int color[]){
    queue<int> q;
    q.push(0);
    color[0] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto x:adj[node]){
            if(color[x]==-1){
                color[x] = 1-color[node];
                q.push(x);
            }
            else if(color[x]==color[node]){
                return false;
            }
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
            if(check(i,V,adj,color)==false) return false; 
        }
    }

    return true;
}

// TC -> same as bfs
// SC -> same as bfs