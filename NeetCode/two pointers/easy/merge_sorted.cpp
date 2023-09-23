#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/merge-sorted-array/
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr = nums1 ;
        int index = 0 ;
        nums1.resize(m+n) ;
        fill(nums1.begin(), nums1.end(), 0) ;
        int i = 0 ;
        int j = 0 ;
        while(i < m && j < n){
            if(arr[i] <= nums2[j]){
                nums1[index++] = arr[i++] ;
            }
            else{
                nums1[index++] = nums2[j++] ;
            }
        }
        while(i < m){
            nums1[index++] = arr[i++] ;
        }
        while(j < n){
            nums1[index++] = nums2[j++] ;
        }
    }
};