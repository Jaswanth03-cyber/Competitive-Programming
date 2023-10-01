#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/4sum/
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size() ;
        vector<pair<int, int>> arr(n, {0,0}) ;
        sort(nums.begin(), nums.end()) ;

        vector<vector<int>> ans ;
        vector<int> temp ;

        for(int i = 0 ; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1]){ // to avoid duplicates
                continue ; 
            }
            for(int j = i + 1 ; j < n ; j++){
                if(j > (i+1) && nums[j] == nums[j-1]){ // to avoid duplicates
                    continue ; 
                }
                int l = j+1 , r = n-1 ;
                while(l < r){
                    long long sum = long(nums[i]) +long(nums[j]) + long(nums[l]) + long(nums[r]) ;
                    if(sum == target){
                        temp = {nums[i], nums[j], nums[l], nums[r]} ;
                        ans.push_back(temp) ;
                        l++ ;
                        while(nums[l-1] == nums[l] && l < r){ //  to avoid duplicates
                            l++ ;
                        }
                    }
                    else if(sum > target){
                        r-- ;
                    }
                    else{
                        l++ ;
                    }
                }
            }
        }
        return ans ; 
    }
};