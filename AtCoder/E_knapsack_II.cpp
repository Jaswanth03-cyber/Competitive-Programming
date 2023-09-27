#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(vector<ll> &weights, vector<int> &values, ll req){
    int n = values.size() ;
    ll mod = 1e10 + 7 ;
    int total = accumulate(values.begin(), values.end(), 0) ;
    vector<vector<ll>> dp(n+1, vector<ll>(total+1, mod)) ;
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 0 ;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= total ; j++){
            if(values[i-1] > j){
                dp[i][j] = dp[i-1][j] ;
            }
            else{
                dp[i][j] = min(dp[i-1][j-values[i-1]] + weights[i-1], dp[i-1][j]) ;
            }
        }
    }

    int ans = 0 ;
    for(int i = 0 ; i <= total ; i++){
        if(dp[n][i] <= req){
            ans = max(ans, i);
        }
    }
    cout<<ans<<endl ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    ll req = 0 ;
    cin>>n>>req ;

    vector<int> values(n, 0) ;
    vector<ll> weights(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>weights[i]>>values[i] ;
    }

    solve(weights, values, req) ;
    return 0 ;
}