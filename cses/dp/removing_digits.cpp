#include <bits/stdc++.h>
using namespace std ;
/*
Be careful see there when lets say we have the number 
17 
1 2 3 4 5 6 7 8 9 we will get 1 
now at i = 10 and dp[10] is still INT_MAX and digit = 0 so dp[10] = min(dp[10], dp[10]+1) if we add 1 to INT_MAX overflow some negative value so that will be the minimum value so be carefull while
taking minimum and adding a value to IN_MAX and simulalrly subtracting 1 from INT_MIN  

so thats why for every number >= 10 this happens and we got error for it.
*/
int solve(int n){
    vector<int> dp(n+1, INT_MAX) ;
    dp[0] = 0 ;
    int temp = 0 ;
    int digit = 0 ;
    for(int i = 1 ; i <= n ; i++){
        temp = i ;
        while(temp > 0){
            digit = temp%10 ;
            if(dp[i-digit] != INT_MAX){
                dp[i] = min(dp[i], dp[i-digit] + 1) ;
            }
            temp = temp/10 ;
        }
    }
    int ans = dp[n] ;
    return ans ;
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