#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/count-sub-islands/description/
*/
/*
Logic:-
We have to check grid2 island is a subisland of an island in grid1 or not 
for suppose if we are encountering an island in grid2 if for some box in grid2 which is in a island if that box in grid2 is not 1 then
this island will not be the subisland of an island in grid1.

so I have an extra parameter bool check, if value is not same then making it false so in the main function if that check is false then it 
is not a subisland so not increasing the count if it is a subisland then check will be true so count increases.
*/
class Solution {
public:
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &visited, int x, int y, int n, int m, bool &check){
        if(visited[x][y] || grid2[x][y] == 0){
            return ;
        }
        visited[x][y] = true ;
        if(grid1[x][y] != grid2[x][y]){
            check = false ;
        }
        if(x != 0){
            dfs(grid1, grid2, visited, x-1, y, n, m, check) ;
        }
        if(x != n-1){
            dfs(grid1, grid2, visited, x+1, y, n, m, check) ;
        }
        if(y != 0){
            dfs(grid1, grid2, visited, x, y-1, n, m, check) ;
        }
        if(y != m-1){
            dfs(grid1, grid2, visited, x, y+1, n, m, check) ;
        }
        return ;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size() ;
        int m = grid1[0].size() ;
        vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                bool check = true ;
                if(grid2[i][j] && !visited[i][j]){
                    dfs(grid1, grid2, visited, i, j, n, m, check) ;
                    if(check){
                        ans++ ;
                    }
                }
            }
        }
        return ans ; 
    }
};