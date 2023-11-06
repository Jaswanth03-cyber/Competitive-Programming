#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/
*/

class Solution {
public:
    void dfs(vector<vector<int>> &grid, int x, int y, int n, int m, int &sum, vector<vector<bool>> &visited){
        if(!grid[x][y] || visited[x][y]){
            return ;
        }

        visited[x][y] = true ;
        sum += grid[x][y] ;

        if(x != 0){
            dfs(grid, x-1, y, n, m, sum, visited) ;
        }
        if(x != n-1){
            dfs(grid, x+1, y, n, m, sum, visited) ;
        }
        if(y != 0){
            dfs(grid, x, y-1, n, m, sum, visited) ;
        }
        if(y != m-1){
            dfs(grid, x, y+1, n, m, sum, visited) ;
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans =  0 ;
        int n = grid.size() ;
        int m = grid[0].size() ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    int sum = 0 ;
                    vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
                    dfs(grid, i, j, n, m, sum, visited) ;
                    ans = max(ans, sum) ;
                }
            }
        }  
        return ans ;
    }
};