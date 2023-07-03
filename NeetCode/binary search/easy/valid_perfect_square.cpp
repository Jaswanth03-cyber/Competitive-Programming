#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/valid-perfect-square/
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if((num == 0)||(num == 1)){
            return true ;
        }
        double temp1 = sqrt(num) ;
        int temp2 = sqrt(num) ;
        if(temp1 - temp2 != 0){
            return false ;
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
    bool result = ans.isPerfectSquare(n) ;
    cout<<result<<endl ;

    return 0 ;
}