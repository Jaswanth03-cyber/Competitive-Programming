#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/unique-paths/description/
*/
/*
Logic :- as we know when i = 0 or j = 0 we can have only possible path 
so we can reach (i,j) from (i-1, j) or (i, j-1) so we are adding the possible paths to (i, j) will be sum of possible paths from (i-1, j) and (i, j-1)
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 0)) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 1 ;
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

    int n = 0 ;
    int m = 0 ;
    cin>>n>>m ;

    Solution ans ;
    int res = ans.uniquePaths(n, m) ;
    cout<<res<<endl ;
    return 0 ;
}