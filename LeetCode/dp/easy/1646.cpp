#include <bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/get-maximum-in-generated-array/description/
*/
class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> dp(101, 0) ;
        if(n == 0){
            return 0 ; 
        }
        dp[1] = 1 ;
        for(int i = 2 ; i <= n ; i++){
            if(i%2 == 0){
                dp[i] = dp[i/2] ;
            }
            else{
                dp[i] = dp[(i-1)/2] + dp[(i+1)/2] ;
            }
        }
        int ans = *max_element(dp.begin(), dp.end()) ;
        return ans ; 
    }
};