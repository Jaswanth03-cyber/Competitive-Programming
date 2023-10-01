#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/two-sum/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // multimap<int, int> mp ;
        // int n = nums.size() ;
        // for(int i = 0 ; i < n ; i++){
        //     mp.insert({nums[i], i}) ;
        // }
        // vector<int> ans ;
        // for(int i = 0 ; i < n ; i++){
        //     if(mp.find(target-nums[i]) != mp.end() && mp.find(target-nums[i])->second != i){
        //         ans.push_back(i) ;
        //         ans.push_back(mp.find(target-nums[i])->second) ;
        //         break ;
        //     }
        // }
        // return ans ;
        int n = nums.size() ;
        vector<pair<int, int>> arr(n, {0, 0}) ;
        for(int i  = 0 ; i < n ; i++){
            arr[i] = {nums[i], i} ;
        }
        sort(arr.begin(), arr.end()) ;
        int l = 0, r = n - 1 ;
        vector<int> ans(2, 0) ;
        while(l < r){
            if(arr[l].first + arr[r].first == target){
                ans[0] = arr[l].second ;
                ans[1] = arr[r].second ;
                break ;
            }
            else if(arr[l].first + arr[r].first > target){
                r-- ;
            }
            else{
                l++ ;
            }
        }
        return ans ;
    }
};