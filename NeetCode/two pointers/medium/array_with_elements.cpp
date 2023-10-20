#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()) ;
        int n = nums.size() ;
        int l = 0 ;
        int r = n-1 ;
        vector<int> ans(n, 0) ;
        for(int i = 0; i < n ; i++){
            if(i%2 == 0){
                ans[i] = nums[l++] ;
            }
            else{
                ans[i] = nums[r--] ;
            }
        }
        return ans ; 
    }
};

/*
this will never result in a problem at even places numbers in increasing order at odd places numbers in decreasing order.
*/