#include <bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        vector<int> top(m, -1) ;
        vector<int> left(m, 0) ;
        vector<int> right(m, m-1) ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            stack<int> st ;
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    top[j] = i ;
                }
            }

            for(int j = 0 ; j < m ; j++){
                while(!st.empty() && top[j] >= top[st.top()]){
                    st.pop() ;
                }
                if(!st.empty()){
                    left[j] = st.top() + 1;
                }
                st.push(j) ;
            }

            while(!st.empty()){
                st.pop() ;
            }

            for(int j = m-1 ; j >= 0 ; j--){
                while(!st.empty() && top[j] >= top[st.top()]){
                    st.pop() ;
                }
                if(!st.empty()){
                    right[j] = st.top() - 1 ;
                }
                st.push(j) ;
            }

            for(int j = 0 ; j < m ; j++){
                if(i-d[j] == (right[j] - left[j] + 1)){
                    ans = max(ans, i-d[j]) ;
                }
            }
        }
        int res = ans*ans ;
        return res ;
    }
};