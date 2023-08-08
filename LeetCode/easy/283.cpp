#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/move-zeroes/description/
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size() ;
        int count = 0 ;
        int j = 0 ;
        int i = 0 ;
        while(j < n){
            if(nums[j] == 0){
                count++ ;
            }
            else{
                nums[i] = nums[j] ;
                i++ ;
            }
            j++ ;
        }
        while( i < n){
            nums[i] = 0 ;
            i++ ;
        }
    }
};