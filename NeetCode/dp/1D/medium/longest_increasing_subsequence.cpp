#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-increasing-subsequence/description
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0 ;
        vector<int> subseq ;
        subseq.push_back(nums[0]) ;
        int n = nums.size() ;
        for(int i = 1 ; i < n ; i++){
            if(subseq.back() < nums[i]){
                subseq.push_back(nums[i]) ;
            }
            else{
                int index = lower_bound(subseq.begin(), subseq.end(), nums[i]) - subseq.begin() ;
                subseq[index] = nums[i] ;
            }
        }
        ans = subseq.size() ;
        return ans ;
    }
};

/*
this is the typical solution for a longest increasing subsequence but in the cses as n contsraints were high we need to do the
above approach, but this approach helps us in calculating number of subsequnces of that maximum length. for that see number of longest subsequences
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n, 1) ;
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = i+1 ; j < n ; j++){
                if(nums[i] < nums[j]){
                    dp[i] = max(dp[i], dp[j]+1) ;
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end()) ;
        return ans ;
    }
};