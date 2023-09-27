#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/spiral-matrix/
*/
/*
if(i <= j+1) it is just an obseravtion be carefull simple dfs 
*/

class Solution {
public:
    void dfs(vector<vector<int>> &matrix, vector<int> &ans, int x, int y, int n, int m, vector<vector<bool>> &visited){
        if(x < 0 || x > n-1 || y < 0 || y > m-1 || visited[x][y]){
            return ;
        }
        ans.push_back(matrix[x][y]) ;
        visited[x][y] = true ;
        if(x <= y+1){
            dfs(matrix, ans, x, y+1, n, m, visited) ;
        }
        dfs(matrix, ans, x+1, y, n, m, visited) ;
        dfs(matrix, ans, x, y-1, n, m, visited) ;
        dfs(matrix, ans, x-1, y, n, m, visited) ;
        return ;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
        vector<int> ans ;
        dfs(matrix, ans, 0, 0, n, m, visited) ;
        return ans ;
    }
};