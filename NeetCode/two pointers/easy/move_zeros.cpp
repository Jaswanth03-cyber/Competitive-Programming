#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/move-zeroes/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size() ;
        int count = 0 ;
        int j = 0 ;
        int i = 0 ;
        while(j < n){
            if(nums[j]){
                nums[i++] = nums[j] ;
            }
            j++ ;
        }
        while( i < n){
            nums[i] = 0 ;
            i++ ;
        }
    }
};