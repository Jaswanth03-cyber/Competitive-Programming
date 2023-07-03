#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/add-digits/
*/

class Solution {
public:
    long int add(int num){
        long int ans = 0 ;
        while(num != 0){
            ans = ans + num%10 ;
            num = num/10 ;
        }
        return ans ;
    }
    int digits(long int num){
        int ans = 0 ;
        while(num != 0){
            ans = ans+1 ;
            num = num/10 ;
        }
        return ans ;
    }
    int addDigits(int num) {
        if(num <= 9){
            return num ;
        }   
        long int sum = 0 ;
        sum = add(num) ;
        long int temp = 0 ;
        while(digits(sum) != 1){
            temp = sum ;
            sum = add(temp) ;
        }
        int ans = sum ;
        return ans ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    Solution ans ;
    int result = ans.addDigits(n) ;
    cout<<result<<endl ;
    return 0 ;
}