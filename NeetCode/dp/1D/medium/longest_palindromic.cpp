#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-palindromic-substring/description/
*/
/*
Logic :-
Here we are considering a position as center for the palindrome and building the palindrome taking it as the centre
so for odd length l and r initially will be i itself for even length l = i and r will be i + 1 so just checking if s[l] == s[r] then just 
taking that length and checking if that is greater than the maxlength obtained till then 
O(N^2)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length() ;
        int maxlength = 0 ;
        string ans = "" ;
        int curlength = 0 ;
        for(int i = 0 ; i < n ; i++){
            int l = i, r = i ;
            while(l >= 0 && r < n && s[l] == s[r]){
                curlength = r - l + 1 ;
                if(curlength > maxlength){
                    ans = s.substr(l,curlength) ;
                    maxlength = curlength ;
                }
                l-- ;
                r++ ;
            }
            l = i, r = i + 1 ;
            while(l >= 0 && r < n && s[l] == s[r]){
                curlength = r - l + 1 ;
                if(curlength > maxlength){
                    ans = s.substr(l,curlength) ;
                    maxlength = curlength ;
                }
                l-- ;
                r++ ;
            }
        }
        return ans ;
    }
};