#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-common-characters/description/
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size() ;
        vector<vector<int>> freq(n, vector<int>(26, 0)) ;

        for(int i = 0 ; i < n ; i++){
            int m = words[i].length() ;
            for(int j = 0 ; j < m ; j++){
                freq[i][words[i][j] - 'a']++ ;
            }
        }
        vector<string> ans ;
        for(int i = 0 ; i < 26 ; i++){
            int minimum = INT_MAX ;
            char alpha = i + 'a' ;
            for(int j = 0 ; j < n ; j++){
                minimum = min(freq[j][i], minimum) ;
            }
            string s(1, alpha) ;
            if(minimum != 0 && minimum != INT_MAX){
                for(int j = 0 ; j < minimum ; j++){
                    ans.push_back(s) ;
                }
            }
        }
        return ans ; 
    }
};