#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/min-stack/
*/

class MinStack {
public:
    stack<pair<int, int>> st ;
    // int min_so_far ;
    MinStack() {
        // min_so_far = INT_MAX ;
    }
    void push(int val) {
        if(st.empty()){
            st.push(make_pair(val, val)) ;
            // min_so_far = val ;
        }else{
            int top = st.top().second ;
            st.push(make_pair(val, min(top, val))) ;
        }
    }
    void pop() {
        st.pop() ;
    }
    
    int top() {
        int top = st.top().first ;
        return top ; 
    }
    
    int getMin() {
        return st.top().second ;
    }
};