#include <bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/frequency-of-the-most-frequent-element/
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()) ;
        int n = nums.size() ; 
        long int total = 0 ;
        int l = 0, r = 0 ;
        int ans = 0 ;
        while(r < n){
            total += long(nums[r]) ;
            while((long)(r-l+1)*nums[r] > total + k){
                total -= nums[l] ;
                l++ ;
            }
            ans =  max(ans, r-l+1) ;
            r++ ;
        }
        return ans ;
    }
};

/*
basically sorting the elements because if we are choosing an element we have to try to change the nearest element less than to it to get min no of 
operations as we have restriction on the number of operations k we choose to sort 

now here we are having a window lets say l to r now this window will have all the elements as nums[r] if 
sum of all its elements in the window + k >= nums[r]*length of the window 

so basically in a window we are trying to convert all the elements into last element of that window so thats what we are doing 
so ours is a valid window if sum of elements in that window + k >= nums[r]*length so if this is not satisfied in the inner loop we are 
choosing to change the value of l while changing the value of l we are removing the first element of the invalid window and incrementing
the l so we choose max possible window length of a valid window that will be our answer. 
*/