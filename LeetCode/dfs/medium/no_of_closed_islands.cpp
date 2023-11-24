#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-closed-islands/
*/
class Solution {
public:
    void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited, bool &check, int n, int m){
        if(visited[x][y] || grid[x][y] == 1){
            return ;
        }
        if(x == 0 || x == n-1 || y == 0 || y == m-1){
            check = false ;
        }
        visited[x][y] = true ;
        if(x != 0){
            dfs(grid, x-1, y, visited, check, n, m) ;
        }
        if(x != n-1){
            dfs(grid, x+1, y, visited, check, n, m) ;
        }
        if(y != 0){
            dfs(grid, x, y-1, visited, check, n, m) ;
        }
        if(y != m-1){
            dfs(grid, x, y+1, visited, check, n, m) ;
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int ans = 0 ;
        vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
        for(int i = 1 ; i < n-1 ; i++){
            for(int j = 1 ; j < m-1 ; j++){
                if(grid[i][j] == 0 && !visited[i][j]){
                    bool check = true ;
                    dfs(grid, i, j, visited, check, n, m) ;
                    if(check){
                        ans++ ;
                    }
                }
            }
        }
        return ans ; 
    }
};

/*
count the connected components if in the connected component if we have a zero at any of the borders that should not be counted as that can 
not be a closed island so kept a flag if in case the connected component has a cell which is at the border made check as false 
so if check is true then only count is increased and also before doing dfs do not forget to check if visited or not if not checked that 
then check will be true for those cells which you have visited but trying to do dfs again that will increase the count
*/