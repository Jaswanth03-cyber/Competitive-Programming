#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
*/

/*
Logic is that we need to find the minimum value so that we can find p pairs so our search range is from 0 to 1e9 we are taking the mid 
and checking if we can form p pairs of the numbers after sorting that so if we can form p pairs then we will check if there is minimum possible 
value than that so reducing the search range
*/
class Solution {
public:
    bool isvalid(vector<int> &nums, int p, int value){
        int count = 0 ;
        int n = nums.size() ; 
        int i = 0 ;
        while(i < n-1){
            if(abs(nums[i] - nums[i+1]) <= value){
                count++ ;
                i = i+2 ;
            }
            else{
                i++ ;
            }
            if(count == p){
                return true ;
            }
        }
        return false ;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int l = 0 ;
        int r = 1e9 ;   
        int ans = 1e9 ;
        sort(nums.begin(), nums.end()) ;
        if(p ==0){
            return 0;
        }
        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(isvalid(nums, p, mid)){
                ans = min(ans, mid) ;
                r = mid - 1 ;
            }
            else{
                l = mid +1 ;
            }
        }
        return ans ;
    }
};