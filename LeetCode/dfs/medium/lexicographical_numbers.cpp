#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/lexicographical-numbers/
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> temp ;
        for(int i = 1  ; i <= n ; i++){
            temp.push_back(to_string(i)) ;
        }  
        sort(temp.begin(), temp.end()) ;
        vector<int> ans  ;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(stoi(temp[i])) ;
        }
        return ans ; 
    }
};