#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size() ;
        if(n <= 2){
            return false ;
        }
        stack<pair<int, int>> st ;
        st.push({nums[0], nums[0]}) ;
        for(int i =  1 ; i < n ; i++){
            if(st.size() >= 2 && st.top().first > nums[i] && st.top().first != st.top().second){
                return true ;
            }
            st.push({nums[i], min(nums[i], st.top().second)}) ;
        }
        return false ; 
    }
};