#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/intersection-of-multiple-arrays/description/
*/
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size() ;
        int maximum = 0 ;
        int m = 0 ;
        for(int i = 0 ; i < n ; i++){
            m = nums[i].size() ;
            for(int j = 0 ; j < m ; j++){
                maximum = max(maximum, nums[i][j]) ;
            }
        }
        vector<int> count(maximum+1, 0) ;
        for(int i = 0 ; i < n ; i++){
            m = nums[i].size() ;
            for(int j = 0 ; j < m ; j++){
                count[nums[i][j]]++ ;
            }
        }

        vector<int> ans ;
        for(int i = 0 ; i <= maximum ; i++){
            if(count[i] == n){
                ans.push_back(i) ;
            }
        }
        return ans ; 
    }
};