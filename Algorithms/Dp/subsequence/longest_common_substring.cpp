#include <bits/stdc++.h>
using namespace std ;

void solve(){
    string s ;
    string t ;
    cin>>s ;
    cin>>t ;

    int n = s.length() ;
    int m = t.length() ;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)) ;
    int res = 0 ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1 ;
                res = max(res, dp[i][j]) ;
            }
            else{
                dp[i][j] = 0 ;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}

/*
we tend to find the longest common suffix so dp[i][j] denotes if s[i-1] == t[j-1] then longest suffix that ends at position i in s 
and ends at position j starting position in s and t where longest substring starts can be find using the length we got as 
we have longest string that ends at a position i we will get the starting position of the substring
*/