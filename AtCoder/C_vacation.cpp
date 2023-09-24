#include <bits/stdc++.h>
using namespace std ;

/*
Logic :-
here dp[i][j] denotes at ith day considering j as the task what can be the maximum score we can gain 
base case when i = 1 
dp[i][0] = points[i-1][0]  as no previous tasks if we consider 0th task maximum amount we can gain is that only
dp[i][1] = points[i-1][1]  as no previous tasks if we consider 1st task maximum amount we can gain is that only
dp[i][2] = points[i-1][2]  as no previous tasks if we consider 2nd task maximum amount we can gain is that only

now from i = 2 onwards 
dp[i][0] = points[i-1][j] + max(dp[i-1][1], dp[i-1][2]) 
considering we have oth task so maximum amount gained can be as shown as ith day we are doing 0th task prev day can 1st task or 2nd taskso taking maximum of those two
similarly others and we take tha maximum of the dp[i][j] 0<= j <= 2 

so we are basically calculating maximum score we can gain by considering jth task on ith.
*/
void solve(vector<vector<int>> &points){
    int n = points.size() ;
    vector<vector<int>> dp(n+1, vector<int>(3, 0)) ;
    int ans = INT_MIN ;
    for(int i = 1 ; i <= n ; i++){
        ans = INT_MIN ;
        dp[i][0] = points[i-1][0] + max(dp[i-1][1], dp[i-1][2]) ;
        dp[i][1] = points[i-1][1] + max(dp[i-1][0], dp[i-1][2]) ;
        dp[i][2] = points[i-1][2] + max(dp[i-1][1], dp[i-1][0]) ;
        ans = max(dp[i][0], ans) ;
        ans = max(dp[i][1], ans) ;
        ans = max(dp[i][2], ans) ;
    }
    cout<<ans<<endl ;
}
int main(){
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    ios_base::sync_with_stdio(false) ;

    int n = 0 ;
    cin>>n ; 

    vector<vector<int>> points(n, vector<int>(3, 0)) ;

    int x,y,z ;
    for(int i = 0 ; i < n ; i++){
        cin>>x>>y>>z ;
        points[i][0] = x ;
        points[i][1] = y ;
        points[i][2] = z ;
    }

    solve(points) ;

    return 0 ;
}