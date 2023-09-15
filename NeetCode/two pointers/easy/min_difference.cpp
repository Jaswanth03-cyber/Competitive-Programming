#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
*/

/*
Logic :
sorted the array now minimum possible difference will be between take highest - lowest in all possible windows as other combinations return
more difference value but not less
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size() ;
        if(n == 1){
            return 0 ;
        }
        if(k == 1){
            return 0 ;
        }
        int ans = INT_MAX ;
        sort(nums.begin(), nums.end()) ;
        for(int i = 0 ;  i <= n - k ; i++){
            ans = min(ans, nums[i+k-1] - nums[i]) ;
        }
        return ans ; 
    }
};