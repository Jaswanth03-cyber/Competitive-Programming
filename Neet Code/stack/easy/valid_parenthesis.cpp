#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/valid-parentheses/
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st ;
        bool ans = true ;
        if(s.length() == 0){
            return false ;
        }
        if(s.length() == 1){
            return false ;
        }
        for(int i = 0 ; i < s.length() ; i++){
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')){
                st.push(s[i]) ;
            }
            else{
                if(!st.empty()){
                    if(s[i] == ')'){
                        if(st.top() == '('){
                            st.pop() ;
                        }
                        else{
                            ans = false ;
                            break ;
                        }
                    }
                    else if(s[i] == '}'){
                        if(st.top() == '{'){
                            st.pop();
                        }
                        else{
                            ans = false ;
                            break ;
                        }
                    }
                    else{
                        if(st.top() == '['){
                            st.pop() ;
                        }
                        else{
                            ans = false ;
                            break ;
                        }
                    }
                }
                else{
                    ans = false ;
                    break ;
                }
            }
        } 
        if(!st.empty()){
            ans = false ;
        }
        return ans ;
    }
};


int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    string s = " " ;
    cin>>s ;

    Solution ans ;
    bool res = ans.isValid(s) ;
    cout<<s<<endl ;

    return 0 ;
}