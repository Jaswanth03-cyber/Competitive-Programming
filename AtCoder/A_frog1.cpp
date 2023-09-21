#include<bits/stdc++.h>
using namespace std ;

/*
Logic is simple just going through the arrays and taking the minimum possible among the two cases that are possible 
dp[i] it contains the minimum cost required to come at i-1th position from 0.
*/
int solve(vector<int> &stones){
    int n = stones.size() ;
    vector<int> dp(n+1, 0) ;
    dp[0] = 0 ;
    dp[1] = 0 ;
    dp[2] = abs(stones[0] - stones[1]) ;
    for(int i = 3 ; i <= n ; i++){
        dp[i] = min(dp[i-1] + abs(stones[i-2] - stones[i-1]), dp[i-2] + abs(stones[i-3] - stones[i-1])) ;
    }
    return dp[n] ;
}
int main(){
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    ios_base::sync_with_stdio(false) ;

    int n = 0 ;
    cin>>n ;
    vector<int> stones(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>stones[i] ;
    }

    int ans = solve(stones) ;
    cout<<ans<<endl ;
}