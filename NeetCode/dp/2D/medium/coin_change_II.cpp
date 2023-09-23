#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/coin-change-ii/
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end()) ;
        int n = coins.size() ;
        vector<int> dp(amount+1, 0) ;
        dp[0] = 1 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = coins[i] ; j <= amount ; j++){
                dp[j] = dp[j] + dp[j-coins[i]] ;
            }
        }
        return dp[amount] ;
    }
};