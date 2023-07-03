#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/top-k-frequent-elements/
*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp ;
        multimap<int, int, greater<int>> mp2 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp.count(nums[i]) == 0){
                mp.insert({nums[i], 1}) ;
            }
            else{
                mp.find(nums[i])->second++ ;
            }
        } 
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            mp2.insert({it->second, it->first}) ;
        }
        vector<int> ans ; 
        int i = 0 ;
        auto it = mp2.begin() ;
        while(i != k){
            ans.push_back(it->second) ;
            it++ ;
            i++ ;
        }
        return ans ;    
    }
};


int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    int k = 0 ;
    cin>>k ;

    vector<int> nums(n,0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;    
    }

    Solution ans ;

    vector<int> result = ans.topKFrequent(nums, k) ;

    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;

    return 0 ;
}