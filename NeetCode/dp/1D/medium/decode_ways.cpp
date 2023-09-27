#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/decode-ways/
*/

/*
Logic :-
Here maintaining dp[i] which denotes number of ways we can write from 0 to i-1 string so dp[1] will be 1 if s[0] is not 0 
so if that substring exists then number of ways of it will be dp[i-1] and if 2 length substring exists then number of ways for dp[i]
will be dp[i-2] so total number of possible ways is dp[i-1] + dp[i-2].
*/
class Solution {
public:
    int numDecodings(string s) {
        map<string, char> mp ;
        for(int i = 1 ; i <= 26 ; i++){
            mp[to_string(i)] = i ;
        }
        int n = s.length() ;
        vector<int> dp(n+1, 0) ;
        string temp = "" ;
        dp[0] = 1 ; 
        if(s[0] != '0'){
            dp[1] = 1 ;
        }
        for(int i = 2 ; i <= n ; i++){
            temp = s.substr(i-1, 1) ;
            int one = 0 ;
            int two = 0 ;
            if(mp.find(temp) != mp.end()){
                one = dp[i-1] ; 
            }
            temp = s.substr(i-2, 2) ;
            if(mp.find(temp) != mp.end()){
                two = dp[i-2] ;
            }
            dp[i] = one + two ;
        }
        return dp[n] ; 
    }
};