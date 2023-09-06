#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-subarray/
*/
/*
Kadene's algorithm here subarray in the sense non empty contigous array and also note that
if it is defined that subarray can be empty then if so at the end max_so_far is < 0 then make it zero as it can be 
empty subarray for empty subarray sum is zero so zero will be the maximum possible.

this maximum_ending_here is used when that value is < 0 is that value is less than zero we make it zero as if we have positive value or negative
value further adding this negative value still reduces it but not increases it, so thats the reason why we make it zero.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = INT_MIN ;
        int maximum_ending_here = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            maximum_ending_here = maximum_ending_here + nums[i] ;
            if(max_so_far < maximum_ending_here){
                max_so_far = maximum_ending_here ;
            }
            if(maximum_ending_here < 0){
                maximum_ending_here = 0 ;
            }
        }  
        return max_so_far ;  
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ;

    vector<int> nums(n,0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }
    Solution ans ;
    int result = ans.maxSubArray(nums) ;
    cout<<result<<endl ;
    return 0 ;

}