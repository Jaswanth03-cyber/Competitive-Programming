#include <bits/stdc++.h>
using namespace std ;

int solve(vector<vector<char>> &grid){
    int n = grid.size() ;
    vector<vector<int>> dp(n, vector<int>(n, 0)) ;
    int obstacle = n ;
    int mod = 1e9 + 7 ;
    for(int i = 0 ; i < n ; i++){
        if(grid[i][0] == '*'){
            obstacle = i ;
            break ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(i < obstacle){
            dp[i][0] = 1 ;
        }
    }
    obstacle = n ;
    for(int i = 0 ; i < n ; i++){
        if(grid[0][i] == '*'){
            obstacle = i ;
            break ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(i < obstacle){
            dp[0][i] = 1 ;
        }
    }  
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < n ; j++){
            if(grid[i][j] == '.'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod ;
            }
            else{
                dp[i][j] = 0 ;
            }
        }
    }
    int ans = dp[n-1][n-1] ;
    return ans ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int n = 0 ;
    cin>>n ;
    vector<vector<char>> grid(n, vector<char>(n, 'a')) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>grid[i][j] ;
        }
    }
    int ans = solve(grid) ;
    cout<<ans<<endl ;
    return 0 ;
}