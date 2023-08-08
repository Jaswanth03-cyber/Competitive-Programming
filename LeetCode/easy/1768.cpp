#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/merge-strings-alternately/
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0 ;
        int j = 0 ;
        int n = word1.length() ;
        int m = word2.length() ;
        string ans = "" ;
        int size = n + m ;
        int index = 0 ;
        bool check1 = false, check2 = false ;
        while(index < size){
            if(index%2 == 0){
                if(i < n){
                    ans = ans + word1[i++] ;
                }
                else{
                    check1 = true ;
                }
            }
            else{
                if(j < m){
                    ans = ans + word2[j++] ;
                }
                else{
                    check2 = true ;
                }
            }
            index++ ;
        }
        if(check1){
            for(int k = j ; k < m ; k++){
                ans = ans + word2[k] ;
            }
        }
        if(check2){
            for(int k = i ; k < n ; k++){
                ans = ans + word1[k] ;
            }
        }
        return ans ;
    }
};