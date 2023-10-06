#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/sliding-window-maximum/description/
*/
/*
typical sliding window problem and note that I am taking maximum map for easy access of maximum element 
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans ;
        int n = nums.size() ;
        map<int, int, greater<int>> mp ;
        for(int i = 0 ; i < k ; i++){
            mp[nums[i]]++ ;
        }
        for(int i = k ; i < n ; i++){
            ans.push_back(mp.begin()->first) ;
            if(mp[nums[i-k]] > 1){
                mp[nums[i-k]]-- ;
            }
            else{
                mp.erase(mp.find(nums[i-k])) ;
            }
            mp[nums[i]]++ ;
        }
        ans.push_back(mp.begin()->first) ;
        return ans ; 
    }
};