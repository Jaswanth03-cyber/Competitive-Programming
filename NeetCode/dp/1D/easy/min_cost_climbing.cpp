#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/min-cost-climbing-stairs/description/
*/

/*
Logic :-
I am calculating minimum cost to reach ith step we are paying ith step cost and moving to i+1 or i+2 so thats why 
reccursion relation is kept as that 
dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]) as we pay cost[i-1] and go to ith position and dp[i] has minimum cost needed to reach till there
note we have to cross the floors thats why n+1
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int> dp(n+1, 0) ;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]) ;
        }
        int ans = dp[n] ;
        return ans ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    int res = ans.minCostClimbingStairs(nums) ;
    cout<<res<<endl ;
    return 0 ;
}