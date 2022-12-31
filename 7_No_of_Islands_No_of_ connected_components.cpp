// same as previous problem

// BFS approach

// For adjacency matrix
// No of time queue becomes empty is the ans
#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});

    int n = grid.size();
    int m = grid[0].size();
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse in the neighbours and mark them if its a land
        for(int delrow = -1; delrow<=1;delrow++){
            for(int delcol = -1; delcol<=1;delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }

    }
}

int numIslands(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    // Method to initialize nXm matrix to 0 
    vector<vector<int>> vis(n, vector<int>(m,0));

    int cnt = 0;
    for(int row = 0; row<n; row++){
        for(int col = 0; col<m; col++){
            if(!vis[row][col] && grid[row][col]==1){
                cnt++;
                bfs(row,col,vis,grid);
            }
        }
    }
    return cnt;
}

// space complexity -> O(N*N) + O(N)
// Time complexity ->  O(N*N)