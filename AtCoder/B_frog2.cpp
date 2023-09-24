#include <bits/stdc++.h>
using namespace std ;

/*
Logic 
We know dp[0] as 0 here dp[i] denotes minimum cost to reach index i that is being stored over there 
so now from index i we can go from i to i+1, i+2, i+3... i+k till here so we can relax dp[i+j] till here as we are taking the minimum one 
do check if i+j < n or not note that 
at index n-2 only one step away from n-1 here this abs(stones[n-2] - stones[n-1]) can be the minimum one among all so we need to check from index 
i = 0 to i = n-1 not till i = 0 to i = n-k-1 so be careful
*/
void solve(vector<int> &stones, int k){
    int n = stones.size() ;
    vector<int> dp(n, INT_MAX) ;
    dp[0] = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= k ; j++){
            if(i+j < n){
                dp[i+j] = min(dp[i+j], dp[i] + abs(stones[i] - stones[i+j])) ;
            }
        }
    }
    cout<<dp[n-1]<<endl ;
}
int main(){
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    ios_base::sync_with_stdio(false) ;

    int n = 0 ;
    cin>>n ; 
    int k = 0 ;
    cin>>k ; 

    vector<int> stones(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>stones[i] ;
    }

    solve(stones, k) ;

    return 0 ;
}