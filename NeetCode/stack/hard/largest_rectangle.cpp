#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1089482063/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
    
    stack<pair<int, int>> st;
    
    int ans = 0 ;
    int n = height.size() ;
    
    st.push(make_pair(0, height[0]));
    
    for(int i = 1 ; i < n ; i++){
        int left_length = i;
        while(!st.empty() && height[i] <= st.top().second){
            ans = max((((st.top()).second)*(i-((st.top()).first))) , ans);
            left_length = st.top().first;
            st.pop();
        }
        st.push(make_pair(left_length, height[i]));  
    }

    while(!st.empty()){
        ans = max(ans, ((st.top().second)*(n-st.top().first)));
        st.pop();
    }
    return ans; 
    }
};

/*
at a position for a particular height we need to find to what extent towards left we can go and to what extent towards right we can go 
this is what we need 

basically we are storing for a particualr height to what extent we can go towards left now in the inner loop when 
a particualr postion height is being processed and removed in the sense thats the max distance right it can go 

for ex lets say a building of height h which is actually at position i in the array it can go till index l where 0 <= l <= i 
in future somewhere at index r where height[r] < h now height at index i can be extended towards right until this index only 
so we for a height h at index i we can extend it towards right until index r-1 only so we are calculating maximum possible area 
of the tower of height h at index i that value will be at the same time we are updating at what extent this height[r] can be extended towards
left as last one which we process where height[r] <= st.top().second until that index only we can extend this height[r] left.

h*(r-l) that is what we are caculating just take an example you will understand

outside for loop if still there are elements in the stack implies those can be extended till last position towards right.
*/