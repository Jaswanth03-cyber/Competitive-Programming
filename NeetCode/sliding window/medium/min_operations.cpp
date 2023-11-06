#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size() ;
        int total = 0 ;
        for(int i = 0 ; i < n ; i++){
            total += nums[i] ;
        } 
        int req = total - x ;
        if(req < 0){
            return -1 ;
        }
        int l =0, r = 0 ;
        int sum = 0 ;
        int maxlength = -1 ;
        while(r < n){
            sum += nums[r] ;
            while(sum > req){
                sum -= nums[l] ;
                l++ ;
            }
            if(sum == req){
                maxlength = max(r-l+1, maxlength) ;
            }
            r++ ;
        }
        if(maxlength == -1){
            return -1 ;
        }
        return n - maxlength ;
    }
};

/*
logic :-

we have found the total value of the array now subtract the total value of the array from the given value we need to find the min starting or ending
i.e like min prefix + suffix is same as given x instead we can find 

maximum subarray length whose value of elements in the subarray is the total sum of array elements - given value 

so we first find the total sum and we subtract the required value if the required value is < 0 then -1 
so we start from l =0 and r = 0 we add sum to it if sum exceedes the req value we are changing the window starting position so inside loop 
stops when sum <= req  now when sum == req we are noting that length and taking the maximum length one if many possibilities 

at the end if the maximum possible length is -1 then we can not get the value x from given conditions if not return n - maxlength
*/