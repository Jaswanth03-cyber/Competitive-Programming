#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/ugly-number/
*/
class Solution {
public:
    bool isUgly(int n) {
        int temp = n ;
        bool ans = true ;
        bool stop = false ;
        if(n <= 0){
            return false ; 
        }
        for(unsigned int i = 2 ; i*i <= temp; i++){
            while(n%i == 0){
                if(i > 5){
                    stop = true ;
                    break ;
                }
                n = n/i ;
            }
            if(stop){
                ans = false ;
                break ;
            }
        }
        if(n > 5){
            ans = false ;
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

    Solution ans ;
    int res = ans.isUgly(n) ;
    cout<<res<<endl ;
    return 0 ;
}