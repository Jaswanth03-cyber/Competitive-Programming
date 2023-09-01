#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/asteroid-collision/
*/

class Solution {
public:
    int func(int x){
        if(x > 0){
            return 1 ;
        }
        else if(x < 0){
            return -1 ;
        }
        return 0 ;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st ;
        int n = asteroids.size() ;
        int size = 0 ;
        int temp = 0 ;
        int top = 0 ;
        for(int i = 0 ; i < n ; i++){
            size = asteroids[i] ;
            temp = size ;
            while(!st.empty() && st.top()*temp < 0 && st.top() > 0 && temp < 0){
                top = st.top() ;
                st.pop() ;
                if(abs(top) > abs(size)){
                    temp = abs(top)*func(top) ;
                }
                else if(abs(top) < abs(size)){
                    temp = abs(size)*func(size) ;
                }
                else{
                    temp = 0 ;
                }
            }
            if(temp != 0){
                st.push(temp) ;
            }
        }
        vector<int> ans ;
        while(!st.empty()){
            ans.push_back(st.top()) ;
            st.pop() ;
        }
        reverse(ans.begin(), ans.end()) ;
        return ans ;
    }
};