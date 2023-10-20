#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/solving-questions-with-brainpower/
*/
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size() ;
        vector<long long> dp(n, 0) ;
        dp[n-1] = questions[n-1][0] ;

        for(int i = n-2 ; i >= 0 ; i--){
            long long extrapoints = 0 ;
            int j = questions[i][1] + 1 + i ;
            if(j < n){
                extrapoints = dp[j] ;
            }
            dp[i] = max(dp[i+1], questions[i][0] + extrapoints) ;
        }
        return dp[0] ;
    }
};

/*
so dp[i] denotes how much we can score if we start from question number indexed at i 
so dp[n-1] is number of points we can gain from it 

so for a question we can either skip it or solve it if we skip it we go to next question if not if we solve it 
then next questions[i][1] questions should not be solved so two cases can solve it or can skip it take the maximum of the both 

if skip dp[i+1] if not questions[i][0] + dp[i+questions[i][1]+1] subject to the contsraints that i+questions[i][1]+1 < n so we have to take the max 
of both so the final answer will be dp[0]
*/