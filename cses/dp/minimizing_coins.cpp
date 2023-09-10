#include <bits/stdc++.h>
using namespace std ;

int solve(vector<int> &coins, int x){
    if(x < 0){
        return -1 ;
    }
    vector<int> dp(x+1, INT_MAX) ;
    int n = coins.size() ;
    dp[0] = 0 ;
    for(int i = 1 ; i <= x ; i++){
        for(int j = 0 ; j < n ; j++){
            if(coins[j] <= i && dp[i-coins[j]] != INT_MAX){
                if(dp[i] == INT_MAX || dp[i] > dp[i-coins[j]] + 1 ){
                    dp[i] = dp[i-coins[j]] + 1  ;
                }
            }
        }
    }
    int ans = dp[x] ;
    if(ans == INT_MAX){
        ans = -1 ;
    }
    return ans ;
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int x = 0 ;
    cin>>n>>x ;
    vector<int> coins(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i] ;
    }

    int ans = solve(coins, x);
    cout<<ans<<endl ;
    return 0 ;
}