#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/
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
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end()) ;
        while(check(original, nums)){
            original = 2*original ;
        }
        return original ;
    }
};