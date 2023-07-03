#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/reverse-bits/
*/


class Solution {
public:
    vector<int> binary(unsigned int n){
        vector<int> ans(32,0) ;
        int i = 31 ;
        unsigned int temp = n ;
        while((temp != 1) && (temp != 0)){
            ans[i] = temp%2 ;
            temp = temp/2 ;
            i-- ;
        }
        ans[i] = temp ;
        return ans ;
    }
    uint32_t reverseBits(uint32_t n) {
        vector<long int> power(32,1) ;
        for(int i = 1 ; i < 32 ; i++){
            power[i] = power[i-1]*2 ;
        } 
        unsigned int temp = n ;
        vector<int> arr = binary(n) ;
        unsigned int result = 0 ;
        for(int i = 0 ; i < 32 ; i++){
            result = result + arr[i]*power[i] ;
        }
        uint32_t final = result ;
        return final ;
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    uint32_t n = 0 ;
    cin>>n ; 

    Solution ans ;
    uint32_t result = ans.reverseBits(n) ;

    cout<<result<<endl ;
    return 0 ;
}