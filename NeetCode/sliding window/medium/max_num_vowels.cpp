#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> st({'a', 'e', 'i', 'o', 'u'}) ;

        int n = s.length() ;
        int ans = 0 ;
        int count = 0 ;
        for(int i = 0 ; i < k ; i++){
            if(st.count(s[i])){
                count++ ;
            }
        }
        for(int i = k ; i < n ; i++){
            ans = max(ans, count) ;
            if(st.count(s[i-k])){
                count-- ;
            }
            if(st.count(s[i])){
                count++ ;
            }
        }
        ans = max(ans, count) ;
        return ans ;
    }
};