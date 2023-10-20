#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/shortest-bridge/
*/
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y, int n, set<pair<int, int>> &island, vector<vector<bool>>& visited){
        if(visited[x][y] || grid[x][y] == 0){
            return ;
        }
        visited[x][y] = true ;
        island.insert({x, y}) ;
        if(x != 0){
            dfs(grid, x-1, y, n, island, visited) ;
        }
        if(x != n-1){
            dfs(grid, x+1, y, n, island, visited) ;
        }
        if(y != 0){
            dfs(grid, x, y-1, n, island, visited) ;
        }
        if(y != n-1){
            dfs(grid, x, y+1, n, island, visited) ;
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size() ;
        vector<vector<bool>> visited(n, vector<bool>(n, false)) ;
        set<pair<int, int>> island1, island2 ;
        int count = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] && !visited[i][j]){
                    if(count == 0){
                        dfs(grid, i, j, n, island1, visited) ;
                        count++ ;
                    }
                    else{
                        dfs(grid, i, j, n, island2, visited) ;
                    }
                }
            }
        }
        int ans = INT_MAX ;
        int x1, x2, y1, y2 ;
        for(auto it = island1.begin() ; it != island1.end() ; it++){
            x1 = it->first ;
            y1 = it->second ;
            for(auto it1 = island2.begin() ; it2 != island2.end() ; it1++){
                x2 = it1->first ;
                y2 = it1->second ;
                ans = min(ans, abs(x2-x1) + abs(y2-y1)-1) ;
            }
        }
        return ans ;
    }
};

/*
finding the two islands and taking the minimum manhattan distance -1 of two islands.
that many changes are required
*/