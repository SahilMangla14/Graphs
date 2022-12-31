// Multiple source shortest path algo
// helps to detect negative cycles as well
// Only for directed, for undirected we need to convert it into directed
// Intution behind this algo -> go via every vertex/node

#include<bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1){
                matrix[i][j] = 1e9;
            }
            if(i==j) matrix[i][j] = 0;
        }
    }

    for(int via = 0; via<n; via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][via]+matrix[via][j]);
            }
        }
    }

    // To check negative cycle
    // for(int i=0;i<n;i++){
    //     if(matrix[i][i]<0) return true; // contains negative cycle
    // }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1e9){
                matrix[i][j] = -1;
            }
        }
    }
}


#include<bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}