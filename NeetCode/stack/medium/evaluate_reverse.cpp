#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

/*
Logic is simple is that, we are taking the top two values if an operator occurs operating it on the top two values operated value is pushed 
back to the stack, if operator does not occur we just push the integer to the stack.
*/
class Solution {
public:
    int check(string &s){
        int ans = 0 ;
        if(s == "+"){
            ans = 1 ;
        }
        else if(s == "-"){
            ans = 2 ; 
        }
        else if(s == "*"){
            ans = 3 ;
        }
        else if(s == "/"){
            ans = 4 ;
        }
        return ans ;
    }
    int evalRPN(vector<string>& tokens) {
        int eval = 0 ;
        stack<int> st ;
        int n = tokens.size() ;
        bool first = true ;
        int one = 0 ;
        int two = 0 ;
        int op = 0 ;
        for(int i = 0 ; i < n ; i++){
            op = check(tokens[i]) ;
            if(op == 0){
                st.push(stoi(tokens[i])) ;
            }
            else{
                one = st.top() ;
                st.pop() ;
                two = st.top() ;
                st.pop() ;
                if(op == 1){
                    eval = one + two ;
                }
                else if(op == 2){
                    eval = two - one ;
                }
                else if(op == 3){
                    eval = two*one ;
                }
                else{
                    eval = two/one ;
                }
                st.push(eval) ;
            }
        } 
        return st.top() ; 
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    string temp = "" ;
    vector<string> tokens ;
    for(int i = 0 ; i < n ; i++){
        cin>>temp ;
        tokens,push_back(temp) ;
    }

    Solution ans ;
    int res = ans.evalRPN(tokens) ;
    cout<<res<<endl ;

    return 0 ;
}