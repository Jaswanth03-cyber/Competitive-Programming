#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        int count = 0 ;
        for(int i = 0 ; i < m ; i++){
            for(int j = n - 1 ; j >=0  ; j--){
                if(grid[i][j] < 0){
                    count++ ;
                }
            }
        }  
        return count ; 
    }
};