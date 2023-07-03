#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/plus-one/
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() ;

        if(n == 0){
            vector<int> one(1,0) ;
            one[0] = 1 ;
            return one ;
        }
        if(n == 1){
            if(digits[0] < 9){
                digits[0] = digits[0] + 1 ;
                return digits ;
            }
            digits[0] = 1 ;
            digits.push_back(0) ;
            return digits ;
        }
        if(digits[n-1]+1 <= 9){
            digits[n-1] = digits[n-1] + 1 ;
            return digits ;
        }
        digits[n-1] = 0 ;
        int i ;
        for(i = n - 2 ; i >= 1 ; i--){
            if(digits[i] + 1 > 9){
                digits[i] = 0 ;
            }
            else{
                digits[i] = digits[i] + 1 ;
                break ;
            }
        }  
        vector<int> result(n+1, 0) ;
        if(i == 0){
            if(digits[i] + 1 <= 9){
                digits[i] = digits[i] + 1 ;
                return digits ;
            }
            else{
                result[0] = 1 ; 
                return result ;
            }
        } 
        return digits ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    vector<int> digits(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>digits[i] ;
    }

    Solution ans ;

    vector<int> result = ans.plusOne(digits) ;

    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;

    return 0 ;
}