#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-palindromic-subsequence/description/
*/

/*
Logic :-
It is same as longest possible subsequence for given two strings but here as it is given as that sequence should be palindrome
so I have taken the string and the reverse of the string now I have calculated the longest subsequence of these two strings.
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string a = s ;
        reverse(a.begin(), a.end()) ;
        int n = s.length() ;
        vector<vector<int>>  dp(n+1, vector<int>(n+1, 0)) ;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(s[i-1] == a[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
                }
            }
        }
        return dp[n][n] ;
    }
};