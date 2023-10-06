#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/jump-game-ii/
*/

/*
So maintaining a dp table where dp[i] denotes minimum steps required to ith position from 0th position.

we can even do dfs by connecting the nodes according to the nums value at ith position.
connect each node at ith postion with the node at jth postion where i<j<=nums[i]+i and do bfs from 0 and return distance of n-1, if in case dp
is resulting in a tle. as bfs is O(n)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n, n) ;
        dp[0] = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <= nums[i] ; j++){
                if(i+j < n){
                    dp[i+j] = min(dp[i+j], dp[i]+1) ;
                }
            }
        }
        return dp[n-1] ; 
    }
};