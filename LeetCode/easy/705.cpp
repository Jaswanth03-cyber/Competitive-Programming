#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/design-hashset/
*/

class MyHashSet {
public:
    set<int> st ;
    MyHashSet() {
        st.clear() ;
    }
    
    void add(int key) {
        st.insert(key) ;
    }
    
    void remove(int key) {
        if(st.find(key) != st.end()){
            st.erase(st.find(key)) ;
        }
    }
    
    bool contains(int key) {
        if(st.find(key) != st.end()){
            return true ;
        }
        return false ;
    }
};