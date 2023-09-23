#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/jump-game/
*/

/*
Logic :-
Initially our goal is index n-1 if we observe we can reach n-1 if we can reach n-2 and also nums[n-2] > 0 so which means nums[n-2] + n-2 should be 
greater than n-1 similarly we can say that we can reach i if i-1 + nums[i-1] is > i so every time if the condition is satisfying we are decreasing
the goal to which we have to reach so goal is being decreased. finally if our goal is at 0 then it means from 0 we can reach n-1.
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        int goal = n -1 ; 
        for(int i = n -2 ; i >= 0 ; i--){
            if(i+nums[i] >= goal){
                goal = i ;
            }
        }
        if(!goal){
            return true ;
        }
        return false ;
    }
};