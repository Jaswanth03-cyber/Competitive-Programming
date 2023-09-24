#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/permutation-in-string/
*/

/*
maintaining a map of s1 and also for every substring of size s1 checking if map is same or not removing the previous character of the previous substring 
and checking do not forget to check the last substring after the for loop. 
*/
class Solution {
public:
    map<char, int> freq(string s){
        int n = s.length() ;
        map<char, int> mp ;
        for(int i = 0 ; i < n ; i++){
            mp[s[i]]++ ; 
        }
        return mp ;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.length() ;
        int m = s2.length() ;
        if(n > m){
            return false ;
        }
        map<char, int> mp ;
        map<char, int> mp1 = freq(s1) ;
        for(int i = 0 ; i < n ; i++){
            mp[s2[i]]++ ;
        }
        for(int i = n ; i < m ; i++){
            if(mp == mp1){
                return true ;
            }
            if(mp[s2[i-n]] > 1){
                mp[s2[i-n]]-- ;
            }
            else{
                mp.erase(mp.find(s2[i-n])) ;
            }
            mp[s2[i]]++ ;
        }
        if(mp == mp1){
            return true ;
        }
        return false ;
    }
};