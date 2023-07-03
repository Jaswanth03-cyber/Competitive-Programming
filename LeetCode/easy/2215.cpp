#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/find-the-difference-of-two-arrays/
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1 ;
        set<int> st2 ;
        vector<vector<int>> ans ;
        ans.resize(2) ;
        int n = nums1.size() ;
        int m = nums2.size() ;
        for(int i = 0 ; i < n ; i++){
            st1.insert(nums1[i]) ;
        }
        for(int i = 0 ; i < m ; i++){
            st2.insert(nums2[i]) ;
        }
        for(auto it = st1.begin() ; it != st1.end() ; it++){
            if(st2.find(*it) == st2.end()){
                ans[0].push_back(*it) ;
            }
        }
        for(auto it = st2.begin() ; it != st2.end() ; it++){
            if(st1.find(*it) == st1.end()){
                ans[1].push_back(*it) ;
            }
        }
        return ans ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    vector<int> arr1(n, 0) ;
    vector<int> arr2(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr1[i] ;
        cin>>arr2[i] ;
    }
    Solution ans ;
    vector<vector<int>> res = ans.findDifference(arr1, arr2) ;

    int k = 0 ;
    for(int i = 0 ; i < 2 ; i++){
        k = res[i].size() ;
        for(int j = 0 ; j < k ; j++){
            cout<<res[i][j]<<" " ;
        }
        cout<<endl ;
    }
    cout<<endl ;
    return 0 ;
}