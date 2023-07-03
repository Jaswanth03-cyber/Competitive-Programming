#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/arranging-coins/
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int temp = n ;
        if(n == 1){
            return 1 ;
        }
        int ans ;
        for(int i = 1 ; i <= n ; i++){
            if(temp < 0){
                ans = i-2 ;
                break ;
            }
            else if(temp == 0){
                ans = i-1 ;
                break ;
            }
            else{
                temp = temp - i ;
            }
        }
        return ans ;     
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    Solution ans ;
    int result = ans.arrangeCoins(n) ;
    cout<<result<<endl ;
    return 0 ;
}