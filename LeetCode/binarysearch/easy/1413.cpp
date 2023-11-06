#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
*/
class Solution {
public:
    bool check(int val, vector<int> &arr){
        int n = arr.size() ;
        int curr = val ;
        for(int i = 0 ; i < n ; i++){
            if(curr + arr[i] < 1){
                return false ;
            }
            curr = curr + arr[i] ;
        }
        return true ;
    }
    int minStartValue(vector<int>& nums) {
        int l = 1, r = 10000 ;
        int ans = 10000 ; 
        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(check(mid, nums)){
                ans = min(ans, mid) ;
                r = mid - 1 ; 
            }
            else{
                l = mid  +  1 ;
            }
        }
        return ans ;
    }
};