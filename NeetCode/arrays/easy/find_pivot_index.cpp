#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-pivot-index/
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int pivot = -1 ; 
        int n = nums.size() ;
        vector<long> prefixsum(n, 0) ;
        vector<long> suffixsum(n, 0) ;

        prefixsum[0] = nums[0];
        suffixsum[n-1] = nums[n-1] ;

        for(int i = 1 ; i < n ; i++){
            prefixsum[i] = prefixsum[i-1] + nums[i] ;
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            suffixsum[i] = suffixsum[i+1] + nums[i] ;
        }

        for(int i = 0 ; i < n ; i++){
            long one = prefixsum[i] - nums[i] ;
            long two = suffixsum[i] - nums[i] ;
            if(one == two){
                pivot = i ;
                break ;
            }
        }
        return pivot ;

    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ; 
    cin>>n ; 

    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;

    int result = ans.pivotIndex(nums) ;
    cout<<result<<endl ;

    return 0 ; 
}