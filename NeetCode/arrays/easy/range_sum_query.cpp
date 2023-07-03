#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/range-sum-query-immutable/
*/

class NumArray {
public:
    vector<int> arr ;
    vector<int> prefix ;
    int size ;
    void prefixsum(){
        prefix[0] = arr[0] ;
        for(int i = 1 ; i < size ; i++){
            prefix[i] = prefix[i-1] + arr[i] ;
        }
    }
    NumArray(vector<int>& nums) {
        size = nums.size() ;
        arr.resize(size) ;
        for(int i = 0 ; i < size ; i++){
            arr[i] = nums[i] ;
        } 
        prefix.resize(size) ;
        prefixsum() ;
    }
    int sumRange(int left, int right) {
        int ans = prefix[right] - prefix[left] + arr[left] ;
        return ans ;    
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    return 0 ;
}