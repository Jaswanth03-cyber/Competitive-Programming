#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/range-sum-query-2d-immutable/
*/

class NumMatrix {
public:
    vector<vector<int>> mat ;
    vector<vector<int>> prefix ;
    NumMatrix(vector<vector<int>>& matrix) {
        mat.resize(matrix.size()) ;
        for(int i = 0 ; i < matrix.size() ; i++){
            mat[i].resize(matrix[i].size()) ;
            for(int j = 0 ; j < matrix[i].size() ; j++){
                mat[i][j] = matrix[i][j] ;
            }
        }
        prefixsums() ;
    }
    void prefixsums(){
        prefix.resize(mat.size()) ;
        for(int i = 0 ; i < mat.size() ; i++){
            prefix[i].resize(mat[i].size()) ;
            prefix[i][0] = mat[i][0] ;
            for(int j = 1 ; j < mat[i].size() ; j++){
                prefix[i][j] = prefix[i][j-1] + mat[i][j] ;
            }
        }
    }

    int finalsum(int row1, int col1, int row2, int col2){
        int ans = 0 ;
        for(int i = row1 ; i <= row2 ; i++){
            ans = ans + prefix[i][col2] - prefix[i][col1] + mat[i][col1] ;
        }
        return ans ;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = finalsum(row1, col1, row2, col2) ;
        return ans ; 
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    int m = 0 ;

    cin>>n>>m ;
    vector<vector<int>> matrix ;
    matrix.resize(n) ;
    for(int i = 0 ; i < n ; i++){
        matrix[i].resize(m) ;
        for(int j = 0 ; j < m ; j++){
            cin>>matrix[i][j] ;
        }
    }

    NumMatrix mat(matrix);
    return 0 ;
}