#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/permutations/description/
*/
class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited, int n, vector<int> &nums){
        int size = temp.size() ;
        if(size == n){
            ans.push_back(temp) ;
        }
        else{
            for(int i = 0 ; i < n ; i++){
                if(visited[i]){
                    continue ;
                }
                visited[i] = true ;
                temp.push_back(nums[i]) ;
                solve(ans, temp, visited, n, nums) ;
                visited[i] = false ;
                temp.pop_back() ;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        int n = nums.size() ;
        vector<int> temp ;
        vector<bool> visited(n, false) ;
        solve(ans, temp, visited, n, nums) ;
        return ans ;
    }
};