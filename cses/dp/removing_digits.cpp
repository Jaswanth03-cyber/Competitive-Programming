#include <bits/stdc++.h>
using namespace std ;
#define MAX 1e9
int solve(int n){
    vector<int> dp(n+1, MAX) ;
    dp[0] = 0 ;
    int temp = 0 ;
    int digit = 0 ;
    for(int i = 1 ; i <= n ; i++){
        temp = i ;
        while(temp > 0){
            digit = temp%10 ;
            dp[i] = min(dp[i], dp[i-digit]+1) ;
            temp = temp/10 ;
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