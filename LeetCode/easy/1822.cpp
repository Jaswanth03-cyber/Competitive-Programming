#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/sign-of-the-product-of-an-array/
*/
class Solution {
public:
    int signFunc(int x){
        if(x > 0){
            return 1 ;
        }
        else if (x < 0){
            return -1 ;
        }
        return 0 ;
    }
    int arraySign(vector<int>& nums) {
        int pos = 0 , neg = 0, neutral =0 ;
        int n = nums.size() ;
        int sign = 0 ;
        for(int i = 0 ; i < n ; i++){
            sign = signFunc(nums[i]) ;
            if(sign == 1){
                pos++ ;
            }
            else if(sign == -1){
                neg++ ;
            }
            else{
                neutral++ ;
            }
        }

        int ans = 0 ;
        if(neutral > 0){
            ans = 0 ;
        }
        else{
            if(neg%2 == 0){
                ans = 1 ;
            }
            else{
                ans = -1 ;
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
    cin>>n ; 

    vector<int> arr(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }
    Solution ans ;
    int res = ans.arraySign(arr) ;

    cout<<res<<endl ;

    return 0 ;
}