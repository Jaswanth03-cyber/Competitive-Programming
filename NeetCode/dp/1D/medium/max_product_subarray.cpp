#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/maximum-product-subarray/description/
*/

/*
Logic is simple at every index we are maintaining minimum possible product and also maximum possible product due to negative and postive values 
as the maximum product can be from from negative numbers as next number can be negative overall sum will be positive thats why when the number
encountered is zero it will kill the sum thats the reason why we reinitiate the problem from there.
intiially ans can be INT_MIN but I have kept maximum element because lets say we have the array 
[-2, 0, -1] now as when encountered 0 curmax and curmin will be -1 at the end when i = n-1 so ans = max(ans, curmax) will be -1 
to avoid these cases when all possible products is -ve but there is a zero in the array we initialize the ans to the maximum value of the array
as atleast one sum element must be there for subarray, if given zero or more elements should be there in the sub array then we can  just initialize
it to 0 as whenever negative occurs we can not choose any element then the sum will be 0.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto it = max_element(nums.begin(), nums.end()) ;
        int ans = *it ;
        int curmax = 1 ;
        int curmin = 1 ;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                curmin = 1 ;
                curmax = 1 ; 
                continue ;
            }
            int temp1 = curmax*nums[i] ;
            int temp2 = curmin*nums[i] ;
            curmax = max(temp1, temp2) ;
            curmax = max(nums[i], curmax) ;
            curmin = min(temp1, temp2) ;
            curmin = min(nums[i], curmin) ;
            ans = max(ans, curmax) ;
        }
        return ans ; 
    }
};