#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-k-closest-elements/
*/
/*
Why for a sort of vector we are not explicitly defining a struct and doing it ? 
https://stackoverflow.com/questions/61845708/why-custom-comparator-functions-are-passed-in-class-or-struct

I guess so vectors are not implemented in classes watch video solution of this in the neetcode.
*/
typedef pair<int, int> pi ;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pi> st ;
        int n = arr.size() ;
        for(int i = 0 ; i < n; i++){
            int value = abs(arr[i]-x) ;
            st.push_back({value, arr[i]}) ;
        }   
        vector<int> ans ;
        int curr = k ;
        sort(st.begin(), st.end()) ;
        for(auto it = st.begin() ; it != st.end() ; it++){
            if(!curr){
                break ;
            }
            curr-- ;
            ans.push_back(it->second) ;
        }
        sort(ans.begin(), ans.end()) ;
        return ans ;
    }
};