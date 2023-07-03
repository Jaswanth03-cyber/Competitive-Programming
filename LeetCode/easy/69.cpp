#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/sqrtx/
*/

class Solution {
public:
    int mySqrt(int x) {
        double v = abs(sqrt(x)) ;
        int result = v ; 
        return result ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n  ;

    Solution ans ;
    int result = ans.mySqrt(n) ;
    cout<<result<<endl ;
    return 0 ;
}