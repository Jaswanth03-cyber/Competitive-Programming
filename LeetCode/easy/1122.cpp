#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/relative-sort-array/
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans ;
        map<int, int> mp ;
        map<int, bool> mp2 ;
        for(int i = 0 ; i < arr1.size() ; i++){
            if(mp.count(arr1[i]) == 0){
                mp.insert({arr1[i],1}) ;
                mp2.insert({arr1[i], false}) ;
            }
            else{
                mp.find(arr1[i])->second++ ;
            }
        }
        int temp = 0 ;   
        int freq = 0 ;
        vector<bool> check(mp.size(), false) ;
        for(int i = 0 ; i < arr2.size() ; i++){
            freq = mp.find(arr2[i])->second ;
            mp2.find(arr2[i])->second = true ;
            for(int j = 0 ; j < freq ; j++){
                ans.push_back(arr2[i]) ;
            }
        }
        for(auto it = mp2.begin() ; it != mp2.end() ; it++){
            if(!it->second){
                for(int i = 0 ; i < mp.find(it->first)->second ; i++){
                    ans.push_back(mp.find(it->first)->first) ;
                }
            }
        }
        return ans ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    int m = 0 ;

    cin>>n>>m ;

    vector<int> arr1(n,0) ;
    vector<int> arr2(m,0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>arr1[i] ;
    }
    for(int i = 0 ; i < m ; i++){
        cin>>arr2[m] ;
    }

    Solution ans ;
    vector<int> result = ans.relativeSortArray(arr1, arr2) ;

    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}