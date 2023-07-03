#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>()) ;
        return nums[k-1] ;
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ; 
    cin>>n ; 
    int k = 0 ;
    cin>>k ;

    vector<int> nums(n, 0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    int result = ans.findKthLargest(nums, k) ;
    cout<<result<<endl ;

    return 0 ;
}