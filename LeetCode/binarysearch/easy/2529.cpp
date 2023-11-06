#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
*/
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size() ;
        int count1 = 0, count2 = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < 0){
                count1++ ;
            }
            else if(nums[i] == 0){
                count2++ ;
            }
        }
        return max(count1, n-count1-count2) ;
    }
};