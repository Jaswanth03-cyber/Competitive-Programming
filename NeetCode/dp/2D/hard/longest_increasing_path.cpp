#include <bits/stdc++.h>
using namespace std ;


class Solution {
public:
    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int curr, int x, int y, int n, int m){
        if(curr >= matrix[x][y]){
            return 0 ;
        }

        if(dp[x][y] != -1){
            return dp[x][y] ;
        }

        dp[x][y] = 1 ;

        if(x != 0){
            dp[x][y] = max(dp[x][y], 1 + dfs(matrix, dp, matrix[x][y], x-1, y, n, m)) ;
        }
        if(x != n-1){
            dp[x][y] = max(dp[x][y], 1 + dfs(matrix, dp, matrix[x][y], x+1, y, n, m)) ;
        }
        if(y != 0){
            dp[x][y] = max(dp[x][y], 1 + dfs(matrix, dp, matrix[x][y], x, y-1, n, m)) ;
        }
        if(y != m-1){
            dp[x][y] = max(dp[x][y], 1 + dfs(matrix, dp, matrix[x][y], x, y+1, n, m)) ;
        }   

        return dp[x][y] ;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        vector<vector<int>> dp(n, vector<int>(m, -1)) ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = max(ans, dfs(matrix, dp, -1, i, j, n, m)) ;
            }
        }  
        return ans ;
    }
};

/*
its just like normal dfs on a grid and we also maintain a currvalue which will help in maintaing the currvalue so if increasing we continue else 
we will not continue if already computed then we return it else we calculate it we can use already computed value just think because there wont be any 
overlaps and we will not reach the src again from where we started.
*/