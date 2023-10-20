#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-window-substring/
*/
class Solution {
public:
    unordered_map<char, int> freq(string t){
        int n = t.length() ;
        unordered_map<char, int> mp ;
        for(int i = 0 ; i < n ; i++){
            mp[t[i]]++ ;
        }
        return mp ;
    }
    string minWindow(string s, string t) {
        vector<int> index ;
        int n = s.length() ;
        int m = t.length() ;
        if(m  == 0){
            return "" ;
        }
        unordered_map<char, int> mp = freq(t) ;
        int minlength = n + 1 ;
        int start = 0 ;
        int l = 0, r = 0 ;
        string ans ;
        int counter = m ;
        while(r < n){
            if(mp[s[r]] > 0){
                counter-- ;
            }
            mp[s[r]]-- ;

            while(counter == 0){
                if( r - l + 1 < minlength){
                    minlength = r - l + 1 ;
                    start = l ;
                }
                mp[s[l]]++ ;
                if(mp[s[l]] > 0){
                    counter++ ;
                }
                l++ ;
            }
            r++ ;
        }
        if(minlength == n+1){
            return "" ;
        }
        ans = s.substr(start, minlength) ;
        return ans ; 
    }
};

/*
so basically we have to search substrings key note is that our starting postions of substrings will be the character postions which are present in t 
so one of the idea can be take all the characters positions where that character is in t now for all these positions traverse through the string s 
and we will have a map which is same as that of map of t so now as we traverse remove elements of the map if present or decrement if frequency is more
so if map size is 0 we can note the length if it is min update the length but tle 2 cases failed can still do better 


so the thing is that we start from 0 we also maintain a counter and the map of t now we decrement the counter if we encounter a character in t 
now if the counter is zero we got a valid window which has t in it, now we need to update the left pointer so again until when counter becomes non zero
find the valid starting position so next valid starting postion we will get when we encounter a character that is present in the valid window.
for ex 
s = "ADOBECODEBANC", t = "ABC"

nowo when we start at l = 0, r will go till 5 so update the length and now when counter is zero we have to update l so traversing 
through l = 0 to r = 5 if we get a character present in r then new l is this 
as see we are doing mp[s[r]]-- freq of elements other than characters in t will be negative and will become zero when inner loop is encountered 
so the inner loop comes into action when all the characters in t has freq 0 in a valid window, now when while loop is being executed we will encounter
an index when again this freq will be > 0 now this will be our new starting position of the window.
*/