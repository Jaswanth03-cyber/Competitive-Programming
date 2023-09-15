#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/palindromic-substrings/
*/
/*
Logic :- 
Here we are considering a position as center for the palindrome and building the palindrome taking it as the centre
so for odd length l and r initially will be i itself for even length l = i and r will be i + 1 so just checking if s[l] == s[r]so just increasing the count
O(N^2)
*/
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0 ;
        int length = 0 ;    
        int n = s.length() ;
        int l = 0, r = 0 ;
        for(int i = 0 ; i < n ; i++){
            l = i, r = i ;
            while(l >= 0 && r < n && s[l] == s[r]){
                count++ ;
                l-- ;
                r++ ;
            }
            l = i, r = i + 1 ;
            while(l >= 0 && r < n && s[l] == s[r]){
                count++ ;
                l-- ;
                r++ ;
            }
        }
        return count ;
    }
};