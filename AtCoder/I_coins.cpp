#include <bits/stdc++.h>
using namespace std ;


void solve(){
    int n = 0 ;
    cin>>n ;
    vector<double> head(n, 0.0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>head[i] ;
    }

    vector<vector<double>> dp(n+1, vector<double>(n+1, 0.0)) ;
    double zero = 0.0 ;
    double one = 1.0 ;
    dp[0][0] = one ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            if(j == 0){
                dp[i][j] = (1.0 - head[i-1])*(dp[i-1][j]) ;
            }
            else{
                dp[i][j] = (1.0 - head[i-1])*(dp[i-1][j]) + (head[i-1])*(dp[i-1][j-1]) ;
            }
        }
    }

    double ans = zero ;
    for(int i = (n+1)/2 ; i <= n ; i++){
        ans = ans + dp[n][i] ;
    }
    cout<<setprecision(9)<<ans<<endl ; // this was important 
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    
    return 0 ;
}

/*
dp[i][j] denotes tossing n coins and having j heads in that 
so dp[0][0] is 1.0 as probability of having zero heads when zero coins are tossed is 1.0 

dp[i][0] = (1-head[i-1])dp[i-1][0] as 0 heads as just multiply tail probability to the previous one 
if j is not zero 

dp[i][j] = head[i-1]*dp[i-1][j-1] + (1-head[i-1])*dp[i-1][j]

so if ith toss is head then j-1 tosses should come in i-1 and if ith toss is tail then j tosses should come in i-1 

at last answer is adding all those dp[i][j] where j is >= n/2 + 1 as heads should be more than tails and also n is odd to have an upper hand.
*/