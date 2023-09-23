#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i  = 0 ;
        int n = nums.size() ;
        int j = 0 ;
        set<int> st ;
        int ans = 0 ;
        while(j < n){
            if(st.find(nums[j]) == st.end()){
                nums[i++] = nums[j] ;
                st.insert(nums[j]) ;
            }
            j++ ;
        }
        ans = st.size() ;
        return ans ; 
    }
};