#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-peak-element/description/
*/

/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                return 0;
            }
            return 1;
        }
        
        int end = nums.size() - 1;
        int start = 0;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            else if (mid > 0 && nums[mid - 1] > nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
        return -1;
    }
this assumes 
1 2 5 3 5 6 4 is not in the test case
here 3 < both 5s so which side should I go left or right ???
here by default assumed to be left.
what I got 
nums[i] < nums[i-1] && nums[i] > nums[i+1] then change end = mid -1 
nums[i] > nums[i-1] && nums[i] < nums[i+1] then change start = mid + 1 
nums[i] > nums[i-1] && nums[i] > nums[i+1] then return mid
nums[i] < nums[i-1] && nums[i] < nums[i+1] then for this ???
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
int n = 0 ;
        n = nums.size() ;
        if(n ==1){
            return 0 ;
        }
        if(nums[0] > nums[1]){
            return 0 ;
        }
        if(nums[n-2] < nums[n-1]){
            return n-1 ;
        }
        int ans = 0 ;
        for(int i = 1 ; i <= n-2 ; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                ans = i ;
                break ;
            }
        }
        return ans ;
    }
};