#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-islands/description/
*/
/*
Logic :- Normal dfs  if visited or encounter water return 
but here for a box have to check four sides so just kept some cases for x != 0 x-1 can not be visited so for a box depending on the
co ordinates of the box, how many sides it has to visit will be decided
*/
class Solution {
public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y, int n, int m){
        if(grid[x][y] == '0' || visited[x][y]){
            return ;
        }
        visited[x][y] = true ;
        if(x != 0){
            dfs(grid, visited, x-1, y, n, m) ;
        }
        if(y != 0){
            dfs(grid, visited, x, y-1, n, m) ;
        }
        if(x != n -1){
            dfs(grid, visited, x+1, y, n, m) ;
        }
        if(y != m -1){
            dfs(grid, visited, x, y+1, n, m) ;
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int count = 0 ;
        vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    if(!visited[i][j]){
                        count++ ;
                        dfs(grid, visited, i, j, n, m) ;
                    } 
                }
            }
        }
        return count ;
    }
};