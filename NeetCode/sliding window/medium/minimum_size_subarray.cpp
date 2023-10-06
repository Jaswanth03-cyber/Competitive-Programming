#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-size-subarray-sum/
*/

/*
starting from l = 0 and now going through the array if anywhere we find sum >= target we increase l and check if there is smaller sub array than that
do not forget to remove nums[l](we have no use of it later so removing and that subarray has been processed) and nums[r](as we are adding again in the loop)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0 ;
        int n = nums.size() ;
        int sum = 0 ;
        int ans= n+1 ;
        while(l <= r && r < n){
            sum = sum + nums[r] ;
            if(sum >= target){
                ans = min(ans, r-l+1) ;
                sum = sum - nums[l] ;
                sum = sum - nums[r] ;
                l++ ;
            }
            else{
                r++ ;
            }
        } 
        if(ans == n+1){
            ans = 0 ;
        }
        return ans ;
    }
};