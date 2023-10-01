#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() ;
        int l = 0 ;
        int r = n-1 ;   
        vector<int> ans(2,0) ;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                ans[0] = l+1 ;
                ans[1] = r+ 1 ;
                break ;
            }
            else if(numbers[l] + numbers[r] > target){
                r-- ;
            }
            else{
                l++ ;
            }
        }
        return ans ;
    }
};