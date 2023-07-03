#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-1-bits/
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int temp = n ; 
        int ans = 0 ;
        while((temp != 1) && (temp != 0)){
            if(temp%2 == 1){
                ans++ ;
            }
            temp = temp/2 ;
        }
        if(temp == 1){
            ans++ ;
        }
        return ans ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    uint32_t n = 0 ; // its just a unsigned number thats all which confirms 32 bits for the given number 
    cin>>n ; 

    Solution ans ;
    int result = ans.hammingWeight(n) ;
    cout<<result<<endl ;

    return 0 ;
}