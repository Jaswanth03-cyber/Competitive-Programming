#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/jump-game-vii/
*/

/*
normal dp solution dp[0] = true 
so if dp[i] is false need not process to avoid tle so if dp[i] is true we are processing it 
in the range we are writing j = max(index, i+minJump) to avoid useless processing already processed vertices will be processed again and again 
so to avoid that we are keeping track of last processed vertex every time because anyway the indexes before those of min(i+maxJump, n-1) + 1 
even though processed they result the same even though they are not, its not issue.

for example for minjump = 2 and maxjump = 3
000000000 every time useless processing another example
011001110
*/
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length() ;
        vector<bool> dp(n, false) ;   
        if(s[n-1] == '1'){
            return false ;
        } 
        dp[0] = true ;
        int index = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(!dp[i]){
                continue ;
            }
            for(int j = max(index, i+minJump) ; j <= min(n-1, i+maxJump) ; j++){
                if(s[j] == '0'){
                    dp[j] = true ;
                }
            }
            index = min(i+maxJump, n-1) + 1 ;
        }
        return dp[n-1] ;
    }
};