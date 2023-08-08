#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/removing-stars-from-a-string/
*/

class Solution {
public:
    string removeStars(string s) {
        int n = s.length() ;
        stack<char> st ;
        int count = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '*'){
                st.pop() ;
                count++ ;
            }
            else{
                st.push(s[i]) ;
            }
        } 
        if(count == 0){
            return s ;
        }
        string ans = "" ;
        while(!st.empty()){
            ans = st.top() + ans ;
            st.pop() ;
        }

        return ans ;
    }
};