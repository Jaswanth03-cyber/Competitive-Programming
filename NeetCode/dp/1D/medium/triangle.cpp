#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/triangle/
*/

/*
Logic :-
this is similar to vacation problem which we did from atcoder
dp[i][j] maintains the minimum value till there from top 

so dp[0][0] = triangle[0][0]
now from i = 1 till n 
j goes from 0 to i+1 is the length 
now for j = 0 we can arrivev at this only from triangle[i-1][j] no other way
for j = i we can arrive at this only from triangle[i-1][j-1]
but for all j's btwn 0 to i  we can come there either from [i-1][j] or [i-1][j-1] so take the minimum path of those two
finally dp[n-1] this vector contains all the minimum possible paths to those particular cells [n-1][j] for all 0 <= j < n 
so now we take the minimum of those all
*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ;
        vector<vector<int>> dp(n, vector<int>(n, 0)) ;
        dp[0][0] = triangle[0][0] ;

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i + 1 ; j++){
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if(j == i){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j] ;
                }
                else{
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]) ;
                }
            }
        } 
        int ans ;
        auto it = min_element(dp[n-1].begin(), dp[n-1].end()) ;
        ans = *it ;
        return ans ; 
    }
};