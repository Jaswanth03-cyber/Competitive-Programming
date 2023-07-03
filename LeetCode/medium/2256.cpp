/*
2256. Minimum Average Difference

https://leetcode.com/problems/minimum-average-difference/
*/
#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size() ;
        vector<long long> prefixsum(n, 0) ;
        vector<long long> suffixsum(n, 0) ;
        prefixsum[0] = nums[0] ;
        suffixsum[n-1] = nums[n-1] ;
        for(int i = 1 ; i < n ; i++){
            prefixsum[i] = prefixsum[i-1] + nums[i] ;
        }
        
        for(int i = n-2 ; i >= 0 ; i--){
            suffixsum[i] = suffixsum[i+1] + nums[i] ;
        }        
        int minimum = 1e9  ; 
        int index = -1 ; 
        for(int  i = 0 ; i < n ; i++){
            
            if(i != n -1){
                int one = (prefixsum[i])/(i+1) ;
                int two = (suffixsum[i+1])/(n-1-i) ;
                int check = abs(two - one) ;
                if(minimum > check){
                    index = i ; 
                    minimum = check ;
                }
            }
            else{
                int check = abs((prefixsum[i])/(i+1)) ;
                if(minimum > check){
                    index = i ;
                }
            }
        }
        return index ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n = 0 ; 
    cin>>n ; 
    vector<int> arr(n,0) ;


    for(int i = 0 ; i , n ; i++){
        cin>>arr[i] ;
    }

    Solution ans ; 

    int result = ans.minimumAverageDifference(arr) ;
    cout<<result<<endl ;
    return 0 ;
}