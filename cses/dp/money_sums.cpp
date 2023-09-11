#include <bits/stdc++.h>
using namespace std ;


void solve(vector<int> &coins){
    int n = coins.size() ;
    int Max = 0 ;
    for(int i = 0 ; i < n ; i++){
        Max += coins[i] ;
    }

    vector<vector<bool>> dp(n+1, vector<bool>(Max+1, false)) ;

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= Max ; j++){
            if(j == 0){
                dp[i][j] = true ;
            }
            else if(i ==0){
                dp[i][j] = false ;
                // continue ;
            }
            else if(j < coins[i-1]){
                dp[i][j] = dp[i-1][j] ;
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-coins[i-1]] ;
            }
        }
    }
    vector<int> ans ;
    for(int i = 1 ; i <= Max ; i++){
        if(dp[n][i]){
            ans.push_back(i) ;
        }
    }
    int size = ans.size() ;
    cout<<size<<endl ;
    for(int i = 0 ; i < size; i++){
        cout<<ans[i]<<" " ;
    }
    cout<<endl ;
}

void solve1(vector<int> &coins){
    int n = coins.size() ;
    int Max = 0 ;
    for(int i = 0 ; i < n ; i++){
        Max += coins[i] ;
    }

    vector<vector<bool>> dp(n+1, vector<bool>(Max+1, false)) ;
    dp[0][0] = true ;
    for(int i = 1 ; i <= n ; i++){
        dp[i][coins[i-1]] = true ;
        for(int j = 0 ; j <= Max ; j++){
            if(j == 0){
                dp[i][j] = true ;
            }
            if(dp[i-1][j]){
                dp[i][j] = true ;
                dp[i][j+coins[i-1]] = true ;
            }
        }
    }
    vector<int> ans ;
    for(int i = 1 ; i <= Max ; i++){
        if(dp[n][i]){
            ans.push_back(i) ;
        }
    }
    int size = ans.size() ;
    cout<<size<<endl ;
    for(int i = 0 ; i < size; i++){
        cout<<ans[i]<<" " ;
    }
    cout<<endl ;    
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    vector<int> coins(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>coins[i] ;
    }

    solve1(coins) ;
    // solve(coins) ;
    return 0 ;
}