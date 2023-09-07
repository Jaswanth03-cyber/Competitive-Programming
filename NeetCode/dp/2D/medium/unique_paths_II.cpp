#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/unique-paths-ii/description/
*/

/*
Logic :- as we know when i = 0 or j = 0 we can have only possible path here base case changes, if there is any block at some index then 
after that index no path so we will find the first obstacle and make all ones before that obstacle initially obstacle value will be n thinking no obstacle
for first column next we make it m for first row, if there is obstacle at position i, j we can not reach that point so number of ways will be 0 or else
we can reach (i,j) from (i-1, j) or (i, j-1) so we are adding the possible paths to (i, j) will be sum of possible paths from (i-1, j) and (i, j-1)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size() ;
        int m = obstacleGrid[0].size() ;
        vector<vector<int>> dp(n, vector<int>(m, 0)) ;
        int obstacle = n ;
        for(int i = 0 ; i < n ; i++){
            if(obstacleGrid[i][0]){
                obstacle = i ;
                break ;
            }
        }  
        for(int i = 0 ; i < obstacle ; i++){
            dp[i][0] = 1 ;
        } 
        obstacle = m ;
        for(int i = 0 ; i < m ; i++){
            if(obstacleGrid[0][i]){
                obstacle = i ;
                break ;
            }
        }
        for(int i = 0 ; i < obstacle ; i++){
            dp[0][i] = 1 ;
        } 
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                if(obstacleGrid[i][j]){
                    dp[i][j] = 0 ;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
                }
            }
        }
        int ans = dp[n-1][m-1] ;
        return ans ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0, m = 0 ;
    cin>>n>>m ;

    vector<vector<int>> grid(n, vector<int>(m, 0)) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>grid[i][j] ;
        }
    }

    Solution ans ;
    int res = ans.uniquePathsWithObstacles(grid) ;
    cout<<res<<endl ;
    return 0 ;
}