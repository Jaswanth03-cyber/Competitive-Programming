#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/perfect-squares/
*/
/*
Logic
taking the nearest square root of the given number and now searching from 1*1 to near*near of the perfect squares and take the minimum
if dp[i] is the minimum sum of squares of i and 
*/
class Solution {
public:
    int numSquares(int n) {
        set<int> st ;
        for(int i = 1 ; i <= 100 ; i++){
            st.insert(i*i) ;
        }
        if(st.find(n) != st.end()){
            return 1 ;
        }

        vector<int> dp(n+1, INT_MAX) ;
        dp[0] = 1 ;
        dp[1] = 1 ;
        int near = sqrt(n) ;
        for(int i = 2 ; i <= n ; i++){
            if(st.find(i) != st.end()){
                dp[i] = 1 ;
                continue ;
            }
            for(int j = 1 ; j <= near ; j++){
                if(i >= j*j){
                    dp[i] = min(dp[i], dp[i-j*j]+1) ;
                }
            }
        }
        return dp[n] ;
    }
};