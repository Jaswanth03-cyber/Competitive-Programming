#include <bits/stdc++.h>
using namespace std ;

int solve(vector<int> &coins, int x){
    int mod = 1e9 + 7 ;

    vector<int> dp(x+1, 0) ;
    sort(coins.begin(), coins.end()) ;
    int n = coins.size() ;
    dp[0] = 1 ; 
    for(int i = 0 ; i < n ; i++){
        for(int j = coins[i] ; j <= x ; j++){
            dp[j] = (dp[j] + dp[j - coins[i]])%mod ;
        }
    }
    return dp[x] ;
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int x = 0 ;
    cin>>n>>x ;
    vector<int> coins(n, 0) ;
    for(int i = 0 ; i < n ;  i++){
        cin>>coins[i] ;
    }
    int ans = solve(coins, x) ;
    cout<<ans<<endl ;
    return 0 ;
}