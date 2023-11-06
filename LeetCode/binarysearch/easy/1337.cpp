#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
*/

struct comp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)const{
        if(a.first == b.first){
            return a.second < b.second ;
        }
        return a.first < b.first ;
    }
};
class Solution {
public:
    int check(vector<int> &arr){
        int n = arr.size() ;
        int l =0, r = n-1 ;
        int ans = -1 ;
        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(arr[mid] == 1){
                ans = max(ans, mid) ;
                l = mid + 1 ;
            }
            else{
                r = mid - 1 ;
            }
        }
        return ans + 1 ;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vec ;
        int n = mat.size() ;
        for(int i = 0 ; i < n ; i++){
            int count = check(mat[i]) ;
            vec.push_back({count, i}) ;
        }     
        sort(vec.begin(), vec.end(), comp()) ;
        vector<int> ans ;
        for(int i = 0 ; i < k ; i++){
            ans.push_back(vec[i].second) ;
        }
        return ans ;
    }
};