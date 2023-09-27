#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/word-break/
*/
/*
here we are maintaing a dp boolean array from backward if we reach 0 and if do can be true we can return true as we need atleast
one occurence is sufficient we are coming from back because lets say we are having a word at index i which means there is no word from i+1 till n-1
so if a number is occuring at i dp[i] is true over there so the loop goes on if somewhere  from 0 to i at some j from 0 to i it depends on 
the length at j with which it is matching as dp[j] = dp[j+length] if so dp[j] is true there can be an occurence so breaking that if its false no possibility
even though later in the inner loop if some where word can be same but dp[j+length] can be false so there can not be possibility thats why we break the loop.
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length() ; 
        int m = wordDict.size() ;
        vector<bool> dp(n+1, false) ;
        int length = 0 ;
        dp[n] = true ;
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = 0 ; j < m ; j++){
                length = wordDict[j].length() ;
                if(i+length <= n && s.substr(i, length) == wordDict[j]){
                    dp[i] = dp[i+length] ;
                }
                if(dp[i]){
                    break ;
                }
            }
        }
        return dp[0] ;
    }
};