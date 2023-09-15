#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-turbulent-subarray/description/
*/

/*
Logic 
two cases as given in the question so we can have maximum length from any one of those so have to check both 
so simple thing as a subarray 
if(arr[i] > arr[i+1]) when i is even when i is odd then arr[i] < arr[i+1]  now here in both these cases length increases 
else length = 1 as again starting from the next index being greedy here as we want maximum 
before return we are having one ans = max(ans, length) because for i = n-2 if length increases we are adding but not taking maximum 
for ex 
0 8 45 88 48 68 28 55 17 24 
here 17 < 24 24 must be added to length but after doing length++ we are not taking maximum as ans = max(ans, length) is in the else condition
*/
class Solution {
public:
    int case1(vector<int> &arr){
        int n = arr.size() ;
        if(n == 1){
            return 1 ;
        }
        int ans = 0 ;
        int length = 1 ;
        int i = 0 ;
        while(i < n-1){
            if(i%2 == 0){
                if(arr[i] > arr[i+1]){
                    length++ ;
                }
                else{
                    ans = max(ans, length) ;
                    length = 1 ;
                }
            }
            else{
                if(arr[i] < arr[i+1]){
                    length++ ;
                }
                else{
                    ans = max(ans, length) ;
                    length = 1 ;
                }
            }
            i++ ;
        }
        ans = max(ans, length) ;
        return ans ;
    }
    int case2(vector<int> &arr){
        int n = arr.size() ;
        if(n == 1){
            return 1 ;
        }
        int ans = 0 ;
        int length = 1 ;
        int i = 0 ;
        while(i < n-1){
            if(i%2 == 0){
                if(arr[i] < arr[i+1]){
                    length++ ;
                }
                else{
                    ans = max(ans, length) ;
                    length = 1 ;
                }
            }
            else{
                if(arr[i] > arr[i+1]){
                    length++ ;
                }
                else{
                    ans = max(ans, length) ;
                    length = 1 ;
                }
            }
            i++ ;
        }
        ans = max(ans, length) ;
        return ans ;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int ans1 = case1(arr) ;
        int ans2 = case2(arr) ;
        int ans = max(ans1, ans2) ;
        return ans ; 
    }
};