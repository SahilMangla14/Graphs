// tells whether the two nodes belong to the same component or not in costant time
// used in dynamic graphs
// two functions
// 1) findParent()
// 2) union()

// It will tell at anytime whether two nodes belong to the same component or not

// Union can implemented in two ways -> 1) union by rank
//                                      2) union by size


// Initially everyone is the parent of himself

// union pseudocode
// 1) Find the ultimate parent of u and v i.e. pu and pv respectively
// 2) Find rank of pu and pv
// 3) connect smaller rank to larger rank
// If both have the same rank you can connect anyone to anyone, but the rank increases

// Tree will grow at order of logn in worst case
// We will use path compression else if would take lograthimic time to find the ultimate parent in worst case

// Time complexity of union = O(4*alpha) approx O(constant)

// Why we are connecting smaller to larger number? 
// The answer is we do the reverse way, the height increases and path compression take more time

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank,parent,size;
public:    
    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }
};


int main() {

    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findUPar(3) == ds.findUPar(7)){
        cout << "Same\n";
    }
    else cout << "Not Same\n";

    if(ds.findUPar(3) == ds.findUPar(7)){
        cout << "Same\n";
    }
    else cout << "Not Same\n";


    return 0;
}