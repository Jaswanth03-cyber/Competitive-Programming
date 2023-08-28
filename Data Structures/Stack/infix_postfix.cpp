#include <bits/stdc++.h>
using namespace std ;

/*
given a string which is infix string convert the string into a postfix one 
for example refer the following 

https://www.cs.man.ac.uk/~pjj/cs2121/fix.html

*/

int precendence(char c){
    if(c == '+' || c == '-'){
        return 1 ;
    }
    else if(c == '*' || c == '/'){
        return 2 ;
    }
    return 0 ;
}

bool isoperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/') ;
}

string convert(const string &s){
    string ans = "" ;
    int size = s.length() ;
    stack<char> st ;
    for(int i = 0 ; i < size ; i++){
        if(isalnum(s[i])){
            ans = ans + s[i] ;
        }
        else if(s[i] == '('){
            st.push(s[i]) ;
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans = ans + st.top() ;
                st.pop() ;
            }
            if(!st.empty() && st.top() == '('){
                st.pop() ;
            }
        }
        else if(isoperator(s[i])){
            while(!st.empty() && precendence(st.top()) >= precendence(s[i])){
                ans = ans + st.top() ;
                st.pop() ;
            }
            st.push(s[i]) ;
        }
    }
    while(!st.empty()){
        ans = ans + st.top() ;
        st.pop() ;
    }

    return ans ;
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    string infix = "" ;
    cin>>infix ;

    string ans = convert(infix) ;
    cout<<ans<<endl ;
    return 0 ;
}