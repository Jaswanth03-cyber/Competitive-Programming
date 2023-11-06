#include <bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/check-if-n-and-its-double-exist/description/
*/
class Solution {
public:
    int check(int val, vector<int> &arr){
        int n = arr.size() ;
        int l = 0, r = n-1 ;
        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(arr[mid] == val){
                return mid ;
            }
            else if(arr[mid] > val){
                r = mid - 1 ;
            }
            else{
                l = mid + 1 ;
            }
        }
        return -1 ;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end()) ;
        int n = arr.size() ;
        for(int i = 0 ; i < n ; i++){
            int index = check(2*arr[i], arr) ;
            if(index != -1 && index != i){
                return true ;
            }
        }    
        return false ;
    }
};