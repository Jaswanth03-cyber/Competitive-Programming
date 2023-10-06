#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/non-decreasing-array/
*/

/*
So basically what we are doing is that going through the array and now checking that whether nums[i+1] >= nums[i] if so yes then continue otherwise
we have to change it for sure if already change has been done then return false, if not how to change it 

i-1  i  i+1
3    4   2
always there are two choices for use whenever nums[i] > nums[i+1] choices are that we can increase nums[i+1] to nums[i] or decrease nums[i] to nums[i+1]
second one is preferred because we dont know what i+2 element is so it might be even less, so being greedy that just decrease nums[i] and also to the require
amount not more than that because left elements until which we processed might loose the property 
as for ex lets say 2 3 2 4 5  now if we change 3 to -1 then property to the left might fail so we always try to reduce it for required amount or increase
it to required amount. 

here there is also another case if nums[i+1] < nums[i-1] if it is not the case we can decrease nums[i] to nums[i+1] without any problem
like for example 3 4 2 and currently i is 1 so now nums[i+1] < nums[i] and also nums[i+1] < nums[i-1] in these case we prefer the first change 
where we increase the nums[i+1] to nums[i] as to satisfy the property throughout and also there is a case that when there exists not i-1 ie when i = 0
so when i = 0 and nums[i] > nums[i+1] then we have to reduce nums[i] no choice.
we have no choice rather than changing if we encounter a problem so if changes require more than once we have to return false
*/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size() ;
        int count = 0 ;
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i+1] >= nums[i]){
                continue ;
            }
            if(count){
                return false ;
            }
            count++ ;
            if(i == 0 || nums[i+1] >= nums[i-1]){
                nums[i] = nums[i+1] ;
            }
            else{
                nums[i+1] = nums[i] ;
            }
        }
        return true ; 
    }
};