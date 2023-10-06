#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/container-with-most-water/
*/

/*
Just follow the example given fromt that we shoul be able to get an idea.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;
        int ans = 0 ;
        int l = 0, r = n-1 ;
        while(l <= r){
            if(height[l] < height[r]){
                ans = max(ans, height[l]*(r-l)) ;
                l++ ;
            }
            else{
                ans = max(ans, height[r]*(r-l)) ;
                r-- ;
            }
        }
        return ans ; 
    }
};