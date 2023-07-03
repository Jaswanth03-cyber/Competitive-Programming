#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/array-partition/
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()) ;
        int ans = 0 ;
        for(int i = 0 ; i < nums.size() ; i = i + 2){
            ans = nums[i] + ans ;
        } 
        return ans ;   
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ;

    vector<int> nums(2*n, 0) ;
    for(int i = 0 ;i < 2*n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    int result = ans.arrayPairSum(nums) ;
    cout<<result<<endl ;
    return 0 ;
}