#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/
/*
Sliding window technique carefull with the indices and dont forget last comparision as last substring you are lossing
*/
class Solution {
public:
  map<char, int> freq(string s){
    map<char, int> mp ;
    int n = s.length() ;
    for(int i = 0 ; i < n ; i++){
      mp[s[i]]++ ;
    }
    return mp ;
  }
    vector<int> findAnagrams(string s, string p) {
      vector<int> ans ;
      int n = s.size() ;
      int m = p.size() ;
      map<char, int> mp = freq(p) ;
      map<char, int> mp1 ;
      for(int i = 0 ; i < m ; i++){
        mp1[s[i]]++ ;
      }
      int i ;
      for(i = m ; i < n ; i++){
        if(mp == mp1){
          ans.push_back(i-m) ;
        }
        if(mp1[s[i-m]] > 1){
          mp1[s[i-m]]-- ;
        }
        else{
          mp1.erase(mp1.find(s[i-m])) ;
        }
        mp1[s[i]]++ ;
      }
      if(mp == mp1){
        ans.push_back(i-m) ;
      }
      return ans ;
    }
};