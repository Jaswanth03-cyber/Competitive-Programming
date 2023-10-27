#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/best-team-with-no-conflicts/
*/
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> vec ;
        int n = scores.size() ;
        for(int i = 0 ; i < n ; i++){
            vec.push_back({scores[i], ages[i]}) ;
        }

        sort(vec.begin(), vec.end()) ;

        vector<long long> dp(n, 0) ;
        long long ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            dp[i] = vec[i].first ;
            for(int j = 0 ; j < i ; j++){
                if(vec[i].second >= vec[j].second){
                    dp[i] = max(dp[i], dp[j] + vec[i].first) ;
                }
            }
            ans = max(ans, dp[i]) ;
        } 
        return ans ;
   }
};

/*
this question is somewhat of the type of longest increasing subsequence 
at a position i we assume i is in the longest increasing subsequence and calcuclate it using dp[j]

for all j from 0 to i-1 
if vec[i] > vec[j] then dp[i] = max(dp[i], dp[j]+1) initially dp[i] = 1 
similarly here we assume ith person is in the maximum team score and we calculate what is the maximum score we can have that 
person is in the maximum score team. 
*/