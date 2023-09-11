#include <bits/stdc++.h>
using namespace std ;

int solve(int n, int m){
    if(n < m){
        int temp = n ;
        n = m ;
        m = temp ;
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX)) ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(i == j){
                dp[i][j] = 0 ;
            }
            else{
                // vertical cuts
                for(int k = 1 ; k < i ; k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1) ;
                }
                // horizantal cuts
                for(int k = 1 ; k < j ; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1) ;
                }
            }
        }
    }
    return dp[n][m] ;   
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0, m = 0 ;
    cin>>n>>m ;

    int ans = solve(n, m) ;
    cout<<ans<<endl ;

    return 0 ;
}