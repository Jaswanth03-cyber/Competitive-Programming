#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/combination-sum-iv/
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size() ;
        vector<unsigned int> dp(target+1, 0) ;
        dp[0] = 1 ;

        for(int i = 1 ; i <= target ; i++){
            for(int j = 0 ; j < n ; j++){
                cout<<dp[i]<<endl ;

                if(nums[j] <= i && dp[i-nums[j]] != 0){
                    dp[i] = dp[i] + dp[i-nums[j]] ;
                }
            }
        }
        return dp[target] ;
    }
};