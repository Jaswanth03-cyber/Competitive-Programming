#include <bits/stdc++.h>
using namespace std ;

/*
same as buying k products on n days find minimum cost == assigning k persons with n jobs with minimum cost
*/
void solve(vector<vector<int>> &cost){
    int k = cost.size() ;
    int n = cost[0].size() ;

    vector<vector<int>> dp((1<<k), vector<int>(n, INT_MAX)) ;

    for(int i = 0 ; i < n ; i++){
        dp[0][i] = 0;
    }

    for(int i = 0 ; i < k ; i++){
        dp[1<<i][0] = cost[i][0] ;
    }

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < (1<<k) ; j++){
            dp[j][i] = dp[j][i-1] ;
            for(int l = 0 ; l < k ; l++){
                if(j&(1<<l)){
                    if(dp[j^(1<<l)][i-1] !=  INT_MAX){
                        dp[j][i] = min(dp[j][i], cost[l][i] + dp[j^(1<<l)][i-1]) ;
                    }
                }
            }
        }
    }

    cout<<dp[(1<<k)-1][n-1]<<endl ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    int k = 0 ;
    cin>>k ;

    vector<vector<int>> cost(k, vector<int>(n, 0)) ;

    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>cost[i][j] ;
        }
    }

    solve(cost) ;
    return 0 ;
}