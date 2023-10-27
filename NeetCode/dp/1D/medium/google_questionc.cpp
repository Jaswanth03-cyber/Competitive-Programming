#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/discuss/interview-question/3760132/Google-SWE-Intern-OA-2023-(India)
*/
bool isvalid(int target, int number){
    int sum = 0 ;
    while(number > 0){
        sum = sum + number%10 ;
        number = number/10 ;
    }
    if(sum == target){
        return true ;
    }
    return false ; 
}
void solve(){
    int n = 0 ;
    cin>>n ;
    vector<int> data(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>data[i] ;
    }
    int mod = 1e9+7 ;
    vector<vector<int>> dp(n+1, vector<int>(1001, 0)) ;
    int count = 0 ;
    for(int j = 1 ; j <= 1000 ; j++){
        if(isvalid(data[0], j)){
            count++ ;
        }
        dp[0][j] = count%mod ;
    }

    for(int i = 2 ; i <= n ; i++){
        int count = 0 ;
        for(int j = 1 ; j <= 1000 ; j++){
            if(isvalid(data[i-1], j)){
                count = (count + dp[i-1][j-1])%mod ;
            }
            dp[i][j] = count ;
        }
    }

    cout<<dp[n][1000]<<endl ;
}


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}

/*
dp[i][j] denotes counting for numbrs 1 to j until 0 to i 
note it is not dp[i][j] += dp[i-1][j-1]
it is that count only think well he said number of arrays 
*/