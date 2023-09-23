#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/partition-equal-subset-sum/description/
*/

/*
Logic :- 
if the total sum is not a multiple of 2 then false 
now knapsack check if the sum/2 exists or not if exists we can divide the array into two equal parts
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            sum = sum + nums[i] ;
        }
        if(sum%2 != 0){
            return false ;
        }
        int ans = true ;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false)) ;
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = true ;
        }
        for(int i = 1 ; i <= sum ; i++){
            for(int j = 1 ; j <= n ; j++){
                dp[j][nums[j-1]] = true ;
                if(dp[j-1][i]){
                    dp[j][i] = true ;
                    dp[j][i+nums[j-1]] = true ;
                }
            }
        }
        if(dp[n][sum/2]){
            return true ;
        }
        return false ; 
    }
};