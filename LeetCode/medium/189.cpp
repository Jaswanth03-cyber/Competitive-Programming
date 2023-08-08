#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/rotate-array/
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> arr = nums ;
        int size = nums.size() ;
        int index = 0 ;
        for(int i = 0 ; i < size ; i++){
            index = (i+k)%size ;
            nums[index] = arr[i] ;
        }
        return ; 
    }
};