#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
*/

/*
standard sliding window problem first solved the first window sum and then removed the first element of the previous window 
added the last element of the next window and checked if it is greater than the k*threshold 
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long limit = k*threshold ;
        long sum = 0 ;
        for(int i = 0 ; i < k ; i++){
            sum = sum + arr[i] ;
        } 
        int ans = 0 ;
        if(sum >= limit){
            ans++ ;
        }
        int n = arr.size() ;
        for(int i = 1 ; i < n - k + 1 ; i++){
            sum = sum - arr[i-1] + arr[i+k-1];
            if(sum >= limit){
                ans++ ;
            }
        }
        return ans ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int k = 0 ;
    int x = 0 ;
    cin>>n>>k>>x ;
    vector<int> arr(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }
    Solution ans ;
    int result = ans.numOfSubarrays(arr, k, x) ;
    cout<<result<<endl ;
}