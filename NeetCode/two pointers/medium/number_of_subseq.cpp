#include <bis/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
*/
/*
So note that this is a typical two pointer problem what we do is maintain two pointers l = 0 and r = n-1 and also if so sum is greater we decrement the 
r and if in case <= target now we need to calculate the number of subsequences

now note that if [a1,a2,a3,a4] satisfy the condition now number of subsequences in this you have to note that in all the subsqeuences here
a1 must be there as that is the minimum and we have calculated the sum with respect to that minimum only as l is pointing to that 
so number of subsequences with a1 is power(2, 3) where 3 is the length of the remaining observation just compute first three basics you will get the
pattern as given to do %mod have done it while calculating power of 2 also 
*/
class Solution {
public:
    void calculate(vector<int> &dp){
        int mod = 1e9 + 7 ;
        for(int i = 1 ; i <= 100000 ; i++){
            dp[i] = ((dp[i-1]%mod)*(2%mod))%mod ;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()) ;
        int n = nums.size() ;
        int l = 0, r= n-1 ;
        int mod = 1e9 + 7 ;
        vector<int> dp(100001, 1) ;
        calculate(dp) ;
        int ans= 0 ;
        while(l <= r){
            if(nums[l] + nums[r] > target){
                r-- ;
            }
            else{
                ans = (ans+dp[r-l])%mod ;
                l++ ;
            }
        }
        return ans ;
    }
};