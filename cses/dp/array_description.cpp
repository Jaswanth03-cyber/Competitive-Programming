#include <bits/stdc++.h>
using namespace std ;

void solve(){
    int n = 0, m = 0 ;
    cin>>n ;
    cin>>m ;

    vector<int> arr(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }

    int mod = 1e9 + 7 ;
    vector<vector<int>> dp(n+1, vector<int>(m+2, 0)) ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(i == 1){
                if(arr[i-1] == 0 || arr[i-1] == j){
                    dp[i][j] = 1 ;
                }
                else{
                    dp[i][j] = 0 ;
                }
            }
            else{
                if(arr[i-1] == 0 || arr[i-1] == j){
                    dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%mod + dp[i-1][j+1])%mod ;
                }
                else{
                    dp[i][j] = 0 ;
                }
            }
        }
    }

    int ans = 0 ;
    for(int i = 1 ; i <= m ; i++){
        ans = (ans + dp[n][i])%mod ;
    }

    cout<<ans<<endl ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}

/*
ok so we are given some conditions to form an array 
lets come to this in different passion 

lets say we are not having any zeros we are having just empty array we have to fill using the given conditions 

- - - -... - so lets say we are having n positions 

I will define a dp state as follows at ith position number of valid arrays such that ith position has value x

so now 0 to i-1 should be a valid array and also i-1 can only have values x-1, x, x+1

so 
dp[i][x] = dp[i-1][x-1] + dp[i-1][x] + dp[i-1][x+1]
check the corner cases when x = 1 and x = m 

and also our answer will be sum(dp[n][x]) where x going from 1 to m

so now here only some empty places 

so now we will slightly add some condtions to it 
so when i = 1 if in case arr[i-1] is x or 0 then dp[i][x] will be one else will be zero as if that position is zero no of arrays can be 1 similarly 
if it is x then number of arrays is same 1

so we use the dp relation we wrote if arr[i-1] is 0 or x if not it will be zero so thats it 

we are taking size of dp as (n+1)*(m+2) so we will have m+1 also anyway that will be zero for all positions as we are iterating till m only
*/