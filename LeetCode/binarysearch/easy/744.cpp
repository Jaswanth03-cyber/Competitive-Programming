#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size() ;
        int l =0, r = n-1 ;
        char ans = letters[0] ;
        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(letters[mid] > target){
                r = mid - 1 ; 
                ans = letters[mid] ;
            }
            else{
                l = mid + 1 ;
            }
        }
        return ans ;
    }
};