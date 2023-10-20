#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/count-ways-to-build-good-strings/
*/
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0) ;
        dp[0] = 1 ;
        int mod = 1e9 + 7 ;
        for(int i = 1 ; i <= high ; i++){
            int a =0, b = 0 ;
            if(i-zero >= 0){
                a = dp[i-zero] ;
            }
            if(i - one >=0){
                b = dp[i-one] ;
            }
            dp[i] = (a+b)%mod ;
        }
        int ans = 0 ;
        for(int i = low ; i <= high ; i++){
            ans = (ans+dp[i])%mod ;
        }
        return ans; 
    }
};

/*
number of zero length strings is 1 so now we build the strings depending on the available length 
now if lets say we have length n now we are adding zero times 0's remaining length is n-zero so no of
strings of length n-zero will be added to dp[n] and at the same time n-one also 
so dp[n] = dp[n-zero] + dp[n-one]

so base case is dp[0] = 1 and for ex zero = 2, one = 2 no of strings of length 1 = 0, 2 = 2, 3 = 0, 4 = 4... 
*/