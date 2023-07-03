#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/climbing-stairs/
*/

class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n+1, 0) ;
        dp[0] = 1 ;
        vector<int> arr(2,0) ;
        arr[0] = 1 ;
        arr[1]  = 2 ;

        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j < 2 ; j++){
                if(i <= arr[j]){
                    dp[i] = dp[i] + dp[i-arr[j]] ;
                }
            }
        }
        return dp[n] ;
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    int result = 0 ;

    Solution ans ;
    result = ans.climbStairs(n) ;

    cout<<result<<endl ;
    
    return 0 ;
}