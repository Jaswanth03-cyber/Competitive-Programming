#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/longest-uploaded-prefix/
*/
class LUPrefix {
public:
    int currmax ;
    vector<int> uploaded ;
    LUPrefix(int n) {
        uploaded.resize(n+1, -1) ;
        currmax = 0 ;
    }
    
    void upload(int video) {
        uploaded[video-1] = 1 ;
        while(uploaded[currmax] != -1){
            currmax++ ;
        }   
    }
    
    int longest() {
        return currmax ;
    }
};