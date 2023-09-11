#include <bits/stdc++.h>
using namespace std ;

/*
When we have to find answers such that a condition is true for some subsets and false for other subsets then this knapsack chips in
so for the true subsets we require the answer, just build the table you will get the answer 
dp[i][j] denotes with j price maximum number of pages you can buy using the books from 0 to i - 1.
if prices[i-1] > j then we can not buy that book, if not we can buy it or not buy it so we take maximum among the both if we buy it we 
will add number of pages of that book[i-1] 
*/
int solve(vector<int> &prices, vector<int> &pages, int x){
    int n = pages.size() ;
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0)) ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= x ; j++){
            if(j < prices[i-1]){
                dp[i][j] = dp[i-1][j] ;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-prices[i-1]] + pages[i-1]) ;
            }
        }
    }
    return dp[n][x] ;
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int x = 0 ;
    cin>>n>>x ;

    vector<int> prices(n, 0) ;
    vector<int> pages(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>prices[i] ;
    }
    for(int i = 0 ; i < n ; i++){
        cin>>pages[i] ;
    }

    int ans = solve(prices, pages, x) ;
    cout<<ans<<endl ; 
    return 0 ;
}