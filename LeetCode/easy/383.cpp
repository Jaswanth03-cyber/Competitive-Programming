#include<bits/stdc++.h>
usina namespace std ;

/*
https://leetcode.com/problems/ransom-note/
*/

class Solution {
public:
    map<char, int> freq(string &arr){
        map<char, int> mp ;
        int size = arr.size() ;
        for(int i = 0 ; i < size ; i++){
            if(mp.find(arr[i]) != mp.end()){
                mp[arr[i]]++ ;
            }
            else{
                mp.insert({arr[i], 1}) ;
            }
        }
        return mp ;
    }
    bool canConstruct(string ransomNote, string magazine) {
        bool ans = true ;
        map<char, int> mp1 = freq(ransomNote) ;
        map<char, int> mp2 = freq(magazine) ;
        for(auto it = mp1.begin() ; it != mp1.end() ; it++){
            auto it1 = mp2.find(it->first) ;
            if(it1 == mp2.end()){
                ans = false ;
                break ;
            }
            else if(it1->second < it->second){
                ans = false ;
                break ;
            }
        }
        return ans ;
    }
};