#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/target-sum/
*/
/*
Brute force structure was a decision tree which depends on the index and the total value till that time in the decision tree we are either adding the
current number or either subtracting so taking both the possibilities and adding so thats why the arguments are not referenced.
Here we are trying to back track so basically initially we are maintaining a value that is the total so for a number there can be two possibilities
adding and subtracting so we are taking both of them so mp[{index, total}] this denotes number ways starting from the index we can obtain the value total
*/
class Solution {
public:
    int solve(map<pair<int, int>, int> &mp, vector<int> &nums, int index, int total, int target, int n){
        if(index == n){
            if(total == target){
                return 1 ;
            }
            return 0 ;
        }
        if(mp.find({index, total}) != mp.end()){
            return mp[{index, total}] ;
        }

        mp[{index, total}] = solve(mp, nums, index+1, total + nums[index], target, n) + solve(mp, nums, index+1, total - nums[index], target, n) ;

        return mp[{index, total}] ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ;
        map<pair<int, int>, int> mp ;
        int index = 0 ;
        int total = 0 ;
        int ans = solve(mp, nums, index, total, target, n) ;
        return ans ;
    }
};