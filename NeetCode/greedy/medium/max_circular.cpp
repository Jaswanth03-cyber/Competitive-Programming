#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-sum-circular-subarray/description/
*/

/*
Logic is simple as here it is circular not only maximum sub array sum in a linear array we will have another case 
lets say we are having min possible sum from i to j 

0 1 2 3 ... i ... j j+1 ... n - 1

now as it is ciruclar it can be the case that 
j+1 ... n-1, 0... i this sum can also result in maximum possible sum so we are considering that also.

when sum == minimum in the sense all the values in the array are negative so in that case maximum sub array sum that is here maximum will contain
the maximum element of the given array < 0 and sum - minimum = 0 so in that case our ans will be zero which can not be as sub array is non empty 
if it is given that sub array can be empyt then ans can be zero 
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = 0, sum = nums[0], n = nums.size(), maximum = nums[0], Max = nums[0], Min = nums[0], minimum = nums[0] ;

        for(int i = 1 ; i < n ; i++){
            maximum = max(maximum + nums[i], nums[i]) ;
            Max = max(Max, maximum) ;

            minimum = min(minimum + nums[i], nums[i]) ;
            Min = min(Min, minimum) ;
            sum = sum + nums[i] ;
        }
        if(sum != Min){
            ans = max(Max, sum - Min) ;
        }
        else{
            ans = Max ;
        }
        return ans ; 
    }
}

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
    int result = ans.maxSubarraySumCircular(nums) ;
    cout<<result<<endl ;
    return 0 ;

}