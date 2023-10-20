#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
*/
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size() ;
        vector<bool> dp(n, false) ;
        if(n == 1){
            return false ;
        }
        if(nums[n-2] == nums[n-1]){
            dp[n-2] = true ;
        }
        if(n == 2){
            return dp[n-2] ;
        }
        if((nums[n-3] == nums[n-2] && nums[n-2] == nums[n-1]) || ((nums[n-1] - nums[n-2] == 1) && (nums[n-2] - nums[n-3] == 1))){
            dp[n-3] = true ;
        }

        for(int i = n-4 ; i >= 0 ; i--){
            if(nums[i] == nums[i+1]){
                dp[i] = dp[i+2] ;
            }
            if(dp[i]){
                continue ;
            }
            if((nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) || ((nums[i+1] - nums[i] == 1) && (nums[i+2] - nums[i+1]  == 1))){
                dp[i] = dp[i+3] ;
            }
        }
        return dp[0] ;
    }
};  

/*
dp[i] is true if there exists a valid partition from i to n-1 so first base cases
obv dp[n-1] = false as can not partition now n-2 and n-1 if equal then true 
for n-3 only case is that last two choices of valid definition must be satisfied so checking those 

now from i = n-4 to 0 we check for each possibilti so if we first dp[i] = dp[i+2] dp[i] will be true if i+2 to n can have a valid partition 
similalry for other two conditions dp[i] is true if dp[i+3] is true and also 
if we have dp[i] true after first case no need to check other two because we got a valid partition there we might not have a valid partition with the other
two cases as ultimately the sub problems are same that is why if dp[i] is true we are continuing.
*/