#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/
/*
Logic :
I have maintained a map if a character is found we have to remove all the characters before that character when it previously occurred 
just find the index till where we have to erase, erase from there starting at the position where we did not erase yet
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp ;
        int ans = 0 ;
        int n = s.length() ;
        int size = 0 ;
        int index = 0 ;
        int erased = -1 ;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(s[i]) != mp.end()){
                size = mp.size() ;
                index = mp[s[i]] ;
                for(int i = erased+1 ; i <= index ; i++){
                    mp.erase(mp.find(s[i])) ;
                }
                erased = index ;
            }
            ans = max(ans, size) ;
            mp[s[i]] = i ;
        } 
        size = mp.size() ;
        ans = max(ans, size) ;
        return ans ;  
    }
};