#include<bits/stdc++.h>
using namespace std ;


/*
for fibonacci numbers that approach is working greedy one.
*/
int solve(int n){
    int mod = 1e9 + 7 ;
    vector<int> dp(n+1, 0) ;
    dp[0] = 1 ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= 6 ; j++){
            if(j <= i){
                dp[i] = ((dp[i])%mod + (dp[i-j])%mod)%mod ;
            }
        }
    }
    return dp[n] ;
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    int ans = solve(n) ;
    cout<<ans<<endl ;
    return 0 ;
}