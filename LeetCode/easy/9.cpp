#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/palindrome-number/
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false ;
        }
        vector<int> digits ;
        int digit = 0 ;
        while(x != 0){
            digit = x%10 ;
            digits.push_back(digit) ;
            x = x/10 ; 
        }    

        int n = digits.size() ;
        for(int i = 0 ; i < n/2 ; i++){
            if(digits[i] != digits[n-i-1]){
                return false ;
            }
        }
        return true ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ; 
    cin>>n ; 

    Solution ans ;

    bool result = ans.isPalindrome(n) ;
    cout<<result<<endl ;
    return 0 ;
}


