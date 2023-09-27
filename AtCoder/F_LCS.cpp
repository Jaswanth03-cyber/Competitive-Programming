#include <bits/stdc++.h>
using namespace std ;

/*
directions we are writing wrt to the string on rows that is s over here so 'u' in the sense move up being in the same column 
ans 'l' means move left being in the same row.
*/
void obtain(vector<vector<char>> &dir, int i, int j, string &ans, string s){
    if(dir[i][j] == 'n'){
        return ;
    }
    else if(dir[i][j] == 'd'){
        ans = s[i-1] + ans ;
        obtain(dir, i-1, j-1, ans, s) ;
    }
    else if(dir[i][j] == 'l'){
        obtain(dir, i, j-1, ans, s) ;
    }
    else{
        obtain(dir, i-1, j, ans, s) ;
    }
}
void solve(string s, string t){
    int n = s.size() ;
    int m = t.size() ;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)) ;
    vector<vector<char>> dir(n+1, vector<char>(m+1, 'n')) ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1 ;
                dir[i][j] = 'd' ;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j] ;
                dir[i][j] = 'u' ;
            }
            else{
                dp[i][j] = dp[i][j-1] ;
                dir[i][j] = 'l' ;
            }
        }
    }
    string ans ;
    obtain(dir, n, m, ans, s) ;
    cout<<ans<<endl ;
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    string s = "", t = "" ;
    cin>>s>>t ;

    solve(s, t) ;
    return 0 ;
}