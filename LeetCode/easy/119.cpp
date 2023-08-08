#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/pascals-triangle-ii/
*/

class Solution {
public:
    vector<int> binomial(int n){
        vector<vector<int>> coefficients ;
        coefficients.resize(n+1) ;
        for(int i = 0 ; i <= n ; i++){
            coefficients[i].resize(n+1) ;
            coefficients[i][0] = 1 ;
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(j > i){
                    coefficients[i][j] = 0 ;
                }
                else if(i == j){
                    coefficients[i][i] = 1 ;
                }
                else{
                    coefficients[i][j] = coefficients[i-1][j] + coefficients[i-1][j-1] ;
                }
            }
        }
        return coefficients[n] ;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> temp ;
        temp = binomial(rowIndex) ;
        return temp  ;    
    }
};  