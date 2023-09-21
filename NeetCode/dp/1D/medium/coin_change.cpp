#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/coin-change/description/
*/

/*
here dp[0] = 0 as minimum number of coins required is 0 and also see that not only coins[j] <= i but also dp[i-coins[j]] should not be INT_MAX 
as this can be the case that even though less than that i - coins[j] sum can not be obtained by the coins in that case that value 
of dp[i-coins[j]] will still be INT_MAX. do not forget +1 in the reccursion case.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        vector<int> dp(amount+1, INT_MAX) ;
        dp[0] = 0 ;
        for(int i = 1 ; i <= amount ; i++){
            for(int j = 0 ; j < n ; j++){
                if(coins[j] <= i && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1) ;
                }
            }
        } 
        int ans = 0 ;
        ans = dp[amount] ;
        if(dp[amount] == INT_MAX){
            ans = - 1 ;
        }
        return ans ;
    }
};