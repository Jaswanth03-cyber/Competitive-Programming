#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/decode-ways/description/
*/
/*
Logic :-
First I have maitained a map so that it will be easy to check whether a number can be mapped or not
now I have taken a dp vector where dp[i] denotes number of ways of mapping for i length vector
so dp[0] = 1 will be the base case
dp[1] = 1 if s[i-1] is a digit other than 0 as if 0 we can not map it.
now for length i = 2 ; i <= n ; i++ 
now we are taking only s[i-1] if that is present then number of ways of dp[i] will be same as dp[i-1] so add this to dp[i] 
simillarly length 2 if exists dp[i] has this possibility also so we will add dp[i-2] to dp[i] also. 
note no need to add dp[i-1]+1 we are not discovering new way of mapping it already started before so we are checking the type of mapping we are starting
at the start can continue or not. 
dp[i] = dp[i-1] + dp[i-2] we are adding both the possibilities.
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