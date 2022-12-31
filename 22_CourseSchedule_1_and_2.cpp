// Algo used topo sort
// because if task u is performed before v, then in the linear ordering u should be before v

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int N, vector<pair<int,int>> &prerequisites){
    vector<int> adj[N];
    for(auto it: prerequisites){
        adj[it.first].push_back(it.second);
    }

    int indegree[N] = {0};
    for(int i=0;i<N;i++){
        for(auto it:adj[i]) indegree[it]++;
    }

    queue<int> q;
    for(int i=0;i<N;i++){
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

    if(topo.size()==N) return true;
    else return false;
}

// Course schedule 2

vector<int> findOrder(int N, int m, vector<vector<int>> & prerequisites){
    vector<int> adj[N];
    for(auto it: prerequisites){
        adj[it[1]].push_back(it[0]);
    }

    int indegree[N] = {0};
    for(int i=0;i<N;i++){
        for(auto it:adj[i]) indegree[it]++;
    }

    queue<int> q;
    for(int i=0;i<N;i++){
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

    if(topo.size()==N) return topo;
    else return {};
}