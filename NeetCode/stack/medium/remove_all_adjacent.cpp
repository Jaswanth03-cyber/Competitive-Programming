#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st ;  
        for(auto i : s){
            if(!st.empty() && st.top().first ==  i){
                if(st.top().second == k-1){
                    int temp = k-1;
                    while(temp--){
                        st.pop() ;
                    }
                }
                else{
                    st.push({i, st.top().second+1}) ;
                }
            }
            else{
                st.push({i, 1}) ;
            }
        }
        string ans ;
        while(!st.empty()){
            ans.push_back(st.top().first) ;
            st.pop() ;
        }
        reverse(ans.begin(), ans.end()) ;
        return ans ; 
    }
};

/*
maintain the freq count also in the stack if the rop frequency is k just pop all of them
finally at the answer

there is a difference between 
while(!st.empty()){
    ans = ans + st.top() ;
    st.pop() ;
}
and 
while(!st.empty()){
    ans.push_back(st.top()) ;
    st.pop() ;
}
reverse(st.begin(), st.end()) ;

first one is giving memory limit error whereas second is not giving any mle.
probably due to ans = ans + st.top() storing every time a character is added new memory is allocated again and again.
*/