#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/intersection-of-two-arrays/
*/
class Solution {
public:
    bool check(int val, vector<int> &arr){
        int n = arr.size() ;
        int l = 0, r = n-1 ;
        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(arr[mid] == val){
                return true ;
            }
            else if(arr[mid] > val){
                r = mid - 1 ;
            }
            else{
                l = mid + 1 ;
            }
        }
        return false ;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ;
        int m = nums2.size() ;
        vector<int> ans ; 
        sort(nums1.begin(), nums1.end()) ;
        sort(nums2.begin(), nums2.end()) ;
        if(n > m){
            for(int i = 0 ; i < m ; i++){
                if(check(nums2[i], nums1)){
                    if(i > 0 && nums2[i] != nums2[i-1]){
                        ans.push_back(nums2[i]) ;
                    }
                    else if(i == 0){
                        ans.push_back(nums2[i]) ;
                    }
                }
            }
        } 
        else{
            for(int i = 0 ; i < n ; i++){
                if(check(nums1[i], nums2)){
                    if(i > 0 && nums1[i] != nums1[i-1]){
                        ans.push_back(nums1[i]) ;
                    }
                    else if(i == 0){
                        ans.push_back(nums1[i]) ;
                    }
                }
            }
        }
        return ans ;
    }
};