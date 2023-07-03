#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/pascals-triangle/
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans ;
        vector<int> temp(1,1) ;
        ans.push_back(temp) ;

        for(int i = 1 ; i < numRows ; i++){
            temp.clear() ;
            temp = binomial(i) ;
            ans.push_back(temp) ;
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
    vector<vector<int>> result = ans.generate(n) ;

    for(int i = 0 ; i < result.size() ; i++){
        for(int j = 0 ; j < result[i].size() ; j++){
            cout<<result[i][j]<<" " ;
        }
        cout<<endl ;
    }
    return 0 ;
}