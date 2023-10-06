#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-enclaves/
*/
/*
Idea is that for all borders 1st had a dfs it will reach all ones which can reach there so remaining ones in the matrix form the enclaves

I was trying some dp :(
*/
void dfs(vector<vector<int>>& grid, int x, int y, int n, int m, vector<vector<bool>>& visited){
    if(visited[x][y] || grid[x][y] == 0){
        return ;
    }

    visited[x][y] = true ;
    if(x!= 0){
        dfs(grid, x-1, y, n, m, visited) ;
    }
    if(y!= 0){
        dfs(grid, x, y-1, n, m, visited) ;
    }
    if(x!= n-1){
        dfs(grid, x+1, y, n, m, visited) ;
    }
    if(y!= m-1){
        dfs(grid, x, y+1, n, m, visited) ;
    }
}
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
        for(int i = 0 ; i < m ; i++){
            if(grid[0][i] && !visited[0][i]){
                dfs(grid, 0, i, n, m, visited) ;
            }
            if(grid[n-1][i] && !visited[n-1][i]){
                dfs(grid, n-1, i, n, m, visited) ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] && !visited[i][0]){
                dfs(grid, i, 0, n, m, visited) ;
            }
            if(grid[i][m-1] && !visited[i][m-1]){
                dfs(grid, i, m-1, n, m, visited) ;
            }
        }

        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] && !visited[i][j]){
                    count++ ;
                }
            }
        }
        return count ;
    }
};