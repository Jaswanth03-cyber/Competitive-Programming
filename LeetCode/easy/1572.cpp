#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/matrix-diagonal-sum/
*/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0 ;
        int size = mat.size() ;
        if(size%2 == 0){
            for(int i = 0 ; i < size ; i++){
                ans = ans + mat[i][i] ;
                ans = ans + mat[i][size-i-1] ;
           }
        }
        else{
            for(int i = 0 ; i < size ;i++){
                if(i == size/2){
                    ans = ans + mat[i][i] ;
                }
                else{
                    ans = ans + mat[i][i] ;
                    ans = ans + mat[i][size-1-i] ;
                }
            }
        }
        return ans ;
    }
};