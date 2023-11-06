#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-common-value/description/
*/
class Solution {
public:
    bool check(int val, vector<int> &arr){
        int n = arr.size() ;
        int l =0, r = n-1 ;
        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(arr[mid] == val){
                return true ;
            }
            else if(arr[mid] > val){
                r = mid -1 ;
            }
            else{
                l = mid + 1 ;
            }
        }
        return false ;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ;
        int m = nums2.size() ;
        int ans = -1 ;
        for(int i = 0 ; i < m ; i++){
            if(check(nums2[i],nums1)){
                ans = nums2[i] ;
                break ;
            }
        }
        return ans ; 
    }
};