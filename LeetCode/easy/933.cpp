#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-recent-calls/
*/

class RecentCounter {
public:
    set<int> st ;
    RecentCounter() {
        st.clear() ;  
    }
    
    int ping(int t) {
        st.insert(t) ;
        int count = 0 ;
        auto it = st.lower_bound(t-3000) ;
        auto it1 = st.find(t) ;
        for(auto it2 = it ; it2 != it1 ; it2++){
            count++ ;
        }  
        return ++count ; 
    }
};

