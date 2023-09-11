#include <bits/stdc++.h>
using namespace std ;

/*
dp[i][j] is the edit distance for strings text1[i] and text2[j] i, j dentote the length of th text from the starting 
dp[i-1][j] => we are deleting the character i from text1 and dp[i][j-1] in the sense deleting the character from text2
*/
int solve(string text1, string text2){
    int n = text1.size() ;
    int m = text2.size() ;

    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX)) ;
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = i ;
    }
    for(int i = 0 ; i <= m ; i++){
        dp[0][i] = i ;
    }
    int cost = 0 ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(text1[i-1] == text2[j-1]){
                cost = 0 ;
            }
            else{
                cost =1 ;
            }
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1 ;
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + cost) ;  
        }
    }
    return dp[n][m] ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    string text1 = "" ;
    string text2 = "" ;
    cin>>text1>>text2 ;
    int ans = solve(text1, text2) ;
    cout<<ans<<endl ;
    return 0 ;
}