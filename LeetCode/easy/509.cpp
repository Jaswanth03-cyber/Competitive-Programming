#include<bits/stdc++.>
using namespace std ;

/*
https://leetcode.com/problems/fibonacci-number/
*/

[5/25, 21:29] Jaswanth Naidu: class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0 ;
        }
        if(n == 1){
            return 1 ;
        }  
        vector<int> ans(n+1, 0) ;
        ans[0] = 0 ;
        ans[1]  = 1 ;
        for(int i = 2 ; i <= n ; i++){
            ans[i] = ans[i-1] + ans[i-2] ;
        }
        return ans[n] ;
    }
};