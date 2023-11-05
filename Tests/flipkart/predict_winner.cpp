#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/predict-the-winner/description/
*/

typedef long long ll ;
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size() ;
        vector<ll> prefixsum(n, 0) ;
        prefixsum[0] = nums[0] ;
        ll total = ll(nums[0]) ;
        vector<vector<ll>> dp(n, vector<ll>(n, 0)) ;
        dp[0][0] = ll(nums[0]) ;
        for(int i = 1 ; i < n ; i++){
            prefixsum[i] = (ll)nums[i] + prefixsum[i-1] ; 
            total += (ll)nums[i] ;
            dp[i][i] = (ll)nums[i] ;
        }

        for(int size = 2 ; size <= n ; size++){
            for(int i = 0 ; i <= n-size ; i++){
                ll sum = prefixsum[i+size-1] - prefixsum[i] + (ll)nums[i] ;
                dp[i][i+size-1] = max(sum - dp[i+1][i+size-1], sum - dp[i][i+size-2]) ;
            }
        }
        if(dp[0][n-1] >= total - dp[0][n-1]){
            return true ;
        }
        return false ;
    }
};