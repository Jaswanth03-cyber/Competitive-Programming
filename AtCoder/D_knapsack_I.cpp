#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(vector<int> &weights, vector<ll> &values, int req){
    int n = weights.size() ;
    vector<vector<ll>> dp(n+1, vector<ll>(req+1, 0)) ;

    for(ll i = 1 ; i <= req ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(weights[j-1] > i){
                dp[j][i] = dp[j-1][i] ;
            }
            else{
                dp[j][i] = max(dp[j-1][i], dp[j-1][i-weights[j-1]] + values[j-1]) ;
            }
        }
    }
    cout<<dp[n][req]<<endl ;
}
int main(){

    cin.tie(NULL) ;
    cout.tie(NULL) ;
    ios_base::sync_with_stdio(false) ;

    int n = 0 ;
    cin>>n ;
    int req = 0 ;
    cin>>req ;

    vector<int> weights(n, 0) ;
    vector<ll> values(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>weights[i]>>values[i] ;
    }

    solve(weights, values, req) ;
    return 0 ;
}