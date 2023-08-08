#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int, int> mp ;
        int ans = 0 ;
        int size = nums.size() ;
        for(int i = 0 ; i < size ; i++){
            mp.insert({nums[i], i}) ;
        }
        if(mp.find(target) != mp.end()){
            ans = mp[target] ;
        }
        else{
            ans = -1 ;
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
    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    int target = 0 ;
    cin>>target ;

    Solution ans ;
    int res = ans.search(nums, target) ;
    cout<<res<<endl ;
    return 0 ;
}