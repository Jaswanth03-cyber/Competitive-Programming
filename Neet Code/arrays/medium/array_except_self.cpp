#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/product-of-array-except-self/
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> arr(n, 1) ;
        vector<int> prefixproduct(n, 1) ;
        vector<int> suffixproduct(n, 1) ;

        for(int i = 1 ; i < n ; i++){
            prefixproduct[i] = prefixproduct[i-1]*nums[i-1] ;
        } 
        for(int i = n -2 ; i >= 0 ; i--){
            suffixproduct[i] = suffixproduct[i+1]*nums[i+1] ;
        }    

        for(int i = 0 ; i < n ; i++){
            arr[i] = prefixproduct[i]*suffixproduct[i] ;
        }
        return arr ;   
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ;

    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    vector<int> result = ans.productExceptSelf(nums) ;

    for(int i = 0 ; i < n ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;

    return 0 ;
}