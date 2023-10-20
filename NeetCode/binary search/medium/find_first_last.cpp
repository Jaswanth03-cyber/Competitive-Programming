#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1) ;
        int n = nums.size() ;
        int l = 0, r = n-1 ;
        while(l<=r){
            int mid = l + (r-l)/2 ;
            if(nums[mid] == target){
                ans[0] = mid ; 
                if(mid > 0 && nums[mid-1] == target){
                    ans[0] = min(ans[0], mid-1) ;
                    r = mid-1 ;
                }
                else{
                    break ;
                }
            }
            else if(nums[mid] > target){
                r = mid - 1 ;
            }
            else{
                l = mid + 1 ;
            }
        }
        l = 0, r = n-1 ;
        while(l<=r){
            int mid = l + (r-l)/2 ;
            if(nums[mid] == target){
                ans[1] = mid ; 
                if(mid < n-1 && nums[mid+1] == target){
                    ans[1] = max(ans[0], mid+1) ;
                    l = mid+1 ;
                }
                else{
                    break ;
                }
            }
            else if(nums[mid] > target){
                r = mid - 1 ;
            }
            else{
                l = mid + 1 ;
            }
        }
        return ans ; 
    }
};

/*
binary searching if at all nums[mid-1] is also target then binary search in l to mid-1 and take the min of ans[0]
similarly if nums[mid+1]  == target then take the max of ans[1] and search range is mid+1 to r 
*/