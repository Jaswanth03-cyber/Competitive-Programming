#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/powx-n/
*/

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n) ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    double x = 0 ; 
    cin>>x ;
    Solution ans ;
    double result = ans.myPow(x, n) ;

    cout<<result<<endl ;
    return 0 ;
}