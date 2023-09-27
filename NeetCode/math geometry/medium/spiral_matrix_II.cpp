#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/spiral-matrix-ii/
*/
class Solution {
public:
    void dfs(vector<vector<int>> &matrix, int x, int y, int n, int &curr){
        if(x < 0 || x > n-1 || y < 0 || y > n-1 || matrix[x][y] > 0){
            return ;
        }

        matrix[x][y] = curr ;
        curr++ ;
        if(x <= y+1){
            dfs(matrix, x, y+1, n, curr) ;
        }
        dfs(matrix, x+1, y, n, curr) ;
        dfs(matrix, x, y-1, n, curr) ;
        dfs(matrix, x-1, y, n, curr) ;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0)) ;
        int curr = 1 ;
        dfs(matrix, 0, 0, n, curr) ;
        return matrix ;
    }
};