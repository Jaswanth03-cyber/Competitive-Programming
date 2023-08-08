#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/unique-number-of-occurrences/
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp ;
        set<int> st ;
        int n = arr.size() ;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(arr[i]) != mp.end()){
                mp[arr[i]]++ ;
            }
            else{
                mp.insert({arr[i], 1}) ;
            }
        }

        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if(st.find(it->second) != st.end()){
                return false ;
            }
            else{
                st.insert(it->second) ;
            }
        }   
        return true ;
    }
};