#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-zero-filled-subarrays/
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0 ;
        long long length = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                length++ ;
            }
            else{
                if(length > 0){
                    count+=((length)*(length+1))/2 ;
                }
                length = 0 ;
            }
        } 
        count+=((length)*(length+1))/2 ;   
        return count ; 
    }
};