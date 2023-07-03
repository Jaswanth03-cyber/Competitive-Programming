#include<bits/stdc++.h>
using namespace std ;


/*
https://leetcode.com/problems/kth-missing-positive-number/
*/


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int, greater<int>> st ;
        for(int i = 0 ; i < arr.size() ; i++){
            st.insert(arr[i]) ;
        }   

        int ans = 0 ; 
        set<int> st2 ;
        for(int j = 1 ; j <= arr[arr.size()-1] + k ; j++){
            if(st.find(j) == st.end()){
                st2.insert(j) ;
            }
        }
        int count = 0 ;
        for(auto it = st2.begin() ; it != st2.end() ; it++){
            count++ ;
            if(count == k){
                ans = *it ;
                break ;
            }
        }
        return ans ; 
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 

    vector<int> nums(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ; 
    }

    int k = 0 ;
    cin>>k ;
    Solution ans ;
    int result = ans.findKthPositive(nums, k) ;
    cout<<result<<endl ;
    return 0 ;
}