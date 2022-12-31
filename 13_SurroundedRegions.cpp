#include<bits/stdc++.h>
using namespace std;
// Time complexity - O(N*M)
// Space complexity - O(N*M)

void dfs(int row, int col, vector<vector<int>> vis, vector<vector<char>> mat,int delrow[], int delcol[]){
    vis[row][col] = 1;
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='0'){
            dfs(nrow,ncol,vis,mat,delrow,delcol);
        }
    }
}


vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
    vector<vector<int>> vis(n,vector<int>(m,0));
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    for(int j=0;j<m;j++){
        if(!vis[0][j] && mat[0][j]=='0'){
            dfs(0,j,vis,mat,delrow,delcol);
        }

        if(!vis[n-1][j] && mat[n-1][j]=='0'){
            dfs(n-1,j,vis,mat,delrow,delcol);
        }
    }

    for(int i=0;i<n;i++){
        if(!vis[i][0] && mat[i][0]=='0'){
            dfs(i,0,vis,mat,delrow,delcol);
        }

        if(!vis[i][m-1] && mat[i][m-1]=='0'){
            dfs(i,m-1,vis,mat,delrow,delcol);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && mat[i][j] == '0'){
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}

int main(){

    return 0;
}