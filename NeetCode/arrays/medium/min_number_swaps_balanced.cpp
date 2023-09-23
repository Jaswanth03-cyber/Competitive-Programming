#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/
*/
/*
Logic 
We are finding the maximum number of closing brackets at a position without a counter opening bracket
note if we are swapping at a position then number of maximum number of closing brackets without counter opening bracketsmwe try to swap
when we swap then that maximum value decreases by 2 not by 1. so opening encounters and a closing is gone.
*/
class Solution {
public:
    int minSwaps(string s) {
        int n = s.length() ;
        int count = 0 ;
        int Max = INT_MIN ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '['){
                count-- ;
            }
            else{
                count++ ;
                Max = max(Max, count) ;
            }
        }
        int ans = (Max+1)/2 ;
        return ans ; 
    }
};