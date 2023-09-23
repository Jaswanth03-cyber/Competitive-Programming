#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/subsets/description/
*/
class Solution {
public:
    void solve(int n, int index, vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums){
        if(index == n){
            ans.push_back(temp) ;
        }
        else{
            solve(n, index+1, temp, ans, nums) ;
            temp.push_back(nums[index]) ;
            solve(n, index+1, temp, ans, nums) ;
            temp.pop_back() ;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> ans ;
        vector<int> temp ;
        solve(n, 0, temp, ans, nums) ;
        return ans ; 
    }
};