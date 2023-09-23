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