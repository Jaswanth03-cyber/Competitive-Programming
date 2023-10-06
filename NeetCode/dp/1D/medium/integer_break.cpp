#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/integer-break/description/
*/
/*
so for every integer break the number and check the maximum maximum possible can come from any of the following case 
you might mislead that only case is is the first relation as he said it can be product of any numbers k >= 2 whose sum results in n so
thats why we get other two relations also 
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0) ;
        dp[1] = 1, dp[2] = 1 ;

        for(int i = 3 ; i <= n ; i++){
            for(int j = 1 ; j <= i-1 ; j++){
                dp[i] = max(dp[i], j*(i-j)) ;
                dp[i] = max(dp[i], j*dp[i-j]) ;
                dp[i] = max(dp[i], (i-j)*dp[j]) ;
            }
        }
        return dp[n] ; 
    }
};