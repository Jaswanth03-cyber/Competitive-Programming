#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/divisor-game/description/
*/
class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(1001, false) ;
        dp[0] = false ;
        dp[1] = false ;

        for(int i = 2 ; i <= 1000 ; i++){
            for(int j = 1 ; j < i ; j++){
                if(i%j == 0){
                    if(!dp[i-j]){
                        dp[i] = true ;
                        break ;
                    }
                }
            }
        }
        return dp[n] ;
    }
};

/*
at coder type problem 

assuming the turn which a current player is playing as his first turn so dp[i] returns true if he is playing at that time so 
thats why if somehwere dp[i-j] is false then that is optimal dp[i] will be true
*/