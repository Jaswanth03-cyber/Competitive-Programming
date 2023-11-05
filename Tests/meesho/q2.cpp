#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;
void solve(){

    int n = 0 ;
    cin>>n ;
    int k = 0 ;
    cin>>k ;

    vector<ll> dp(n+1, 0) ;

    dp[1] = 26;
    int mod = 1e9 + 7 ;
    for (int i = 2 ; i <= n; i++) {
        if(i < k){
            dp[i] = (dp[i-1]*26)%mod ;
        }
        else if(i == k){
            dp[i] = ((dp[i-1]*26)%mod - 26)%mod ;
        }
        else{
            dp[i] = (dp[i-1]*26 - dp[i-k]*25)%mod ;
        }
    }

    return dp[n];

}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}