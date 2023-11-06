#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/fair-candy-swap/description/
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
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int n = aliceSizes.size() ;
        int m = bobSizes.size() ;
        int total1 = 0 ;
        int total2 = 0 ;
        for(int i = 0 ; i < n ; i++){
            total1 += aliceSizes[i] ;
        }
        for(int i = 0 ; i < m ; i++){
            total2 += bobSizes[i] ;
        }
        sort(bobSizes.begin(), bobSizes.end()) ;
        vector<int> ans ;
        for(int i = 0 ; i < n ; i++){
            int val = (total2 - total1)/2 + aliceSizes[i] ;
            if(check(val, bobSizes)){
                ans.push_back(aliceSizes[i]) ;
                ans.push_back(val) ;
                break ;
            }
        }
        return ans ;
    }
};