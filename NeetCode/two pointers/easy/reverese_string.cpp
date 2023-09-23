#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/reverse-string/description/
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(), s.end()) ;
        int n = s.size() ;
        int l = 0 ;
        int r = n - 1 ;
        char temp ;
        while(l <= r){
            temp = s[l] ;
            s[l] = s[r] ;
            s[r] = temp ;
            l++ ;
            r-- ;
        }
    }
};