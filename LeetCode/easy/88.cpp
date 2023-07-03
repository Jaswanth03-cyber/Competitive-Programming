#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/merge-sorted-array/
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){
            return ;
        }   
        if(m == 0){
            for(int i = 0 ; i < n ; i++){
                nums1[i] = nums2[i] ;
            }
            return ;
        }
        vector<int> arr1(m,0) ;
        for(int i = 0 ; i < m ; i++){
            arr1[i] = nums1[i] ;
        }
        int i = 0 ;
        int ind1 = 0 ; 
        int ind2 = 0 ;
        while((ind1 < m) && (ind2 < n)){
            if(arr1[ind1] < nums2[ind2]){
                nums1[i] = arr1[ind1] ;
                ind1++ ;
            }
            else{
                nums1[i] = nums2[ind2] ;
                ind2++ ;
            }
            i++ ;
        }
        if(ind1 < m){
            while(ind1 < m){
                nums1[i] = arr1[ind1] ;
                ind1++ ;
                i++ ;
            }
        }
        if(ind2 < n){
            while(ind2 < n){
                nums1[i] = nums2[ind2] ;
                ind2++ ;
                i++ ;
            }
        }
        return ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}