#include <bits/stdc++.h>
using namespace std ;


void solve(){
    int n= 0, k = 0 ;
    cin>>n>>k ;

    vector<int> candies(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>candies[i] ;
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0)) ;
    for(int i = 0; i <= n ; i++){
        dp[i][0] = 1 ;
    }
    int mod = 1e9+7 ;
    for(int i = 1 ; i <= n ; i++){
        vector<int> prefixsum(k+1, 0) ;
        prefixsum[0] = dp[i-1][0] ;
        for(int j = 1 ; j <= k ; j++){
            prefixsum[j] = (prefixsum[j-1] + dp[i-1][j])%mod ;
        }

        for(int j = 1 ; j <= k ; j++){
            if(j <= candies[i-1]){
                dp[i][j] = prefixsum[j] ;
            }
            else{
                dp[i][j] = (prefixsum[j] - prefixsum[j-candies[i-1]-1] + mod)%mod ;
            }
        }
    }

    cout<<dp[n][k]<<endl ;
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    solve() ;
    return 0 ;
}

/*
https://www.youtube.com/watch?v=dviTaAZRqCo

this will help in table construction but 


basically lets say we have i people       - - - - ... 
now we are having j candies so let we have computed for i-1 people now we need for i people so last person can take j candies so 
remaining persons so 

dp[i][j] = dp[i-1][j-j] + dp[i-1][j-(j-1)] + dp[i][j-(j-2)] + dp[i-1][j-(j-j)] but the thing is that 
when we are assigning j candies to ith person we have to take care that candies[i] <= j 
so dp[i][j] is depending on the prefix sum of the previous array 

so for j <= a[i] just sum of values from dp[i-1][0] tp dp[i-1][j]
but for j > a[i] we have to take care sum will not be from dp[i-1][0] it will be from 
dp[i-1][j-a[i]] to dp[i-1][j] so last person can be assigned at max till a[i] and min can be 0 so removing those from j 
so we need prexfix sum from k = j - a[i] till j only so prefixsum[j] stores from 0 till j just remove prefixsum[j-a[i]-1] so as subtracting may lead
to problem in mod so just add mod and take modulo 
just write the table you will understand and also just see the base cases.
*/