#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/max-area-of-island/description/
*/

/*
See those corner cases when x and y lies at the border and also do not forget to make size zero after every dfs from the main grid.
*/
class Solution {
public:
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited, int n, int m, int &size){
        if(visited[x][y] || grid[x][y] == 0){
            return ;
        }
        visited[x][y] = true ;
        size++ ;
        if(x != 0){
            dfs(x-1, y, grid, visited,n, m, size) ;
        }
        if(x != n-1){
            dfs(x+1, y, grid, visited, n, m, size) ;
        }
        if(y != 0){
            dfs(x, y-1, grid, visited, n, m, size) ;
        }
        if(y != m-1){
            dfs(x, y+1, grid, visited, n, m, size) ;
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
        int count = 0 ;
        int size = 0 ;
        int Max = INT_MIN ; 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                size = 0 ;
                if(grid[i][j]){
                    if(!visited[i][j]){
                        count++ ;
                        dfs(i, j, grid, visited, n, m, size) ;
                        Max = max(size, Max) ;
                    }
                }
            }
        }
        if(count == 0){
            return 0 ;
        }
        return Max ;
    }
};