#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/first-missing-positive/
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int temp = INT_MAX ;
        set<int> st ;
        for(int i = 0 ; i < nums.size() ; i++){
            st.insert(nums[i]) ;
        }  
        int ans = 0 ;  
        for(int i = 1 ; i <= temp ; i++){
            if(st.find(i) != st.end()){
                st.erase(st.find(i)) ;
                continue ;
            }
            else{
                ans = i ;
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

    vector<int> nums(n,0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    int res = ans.firstMissingPositive(nums) ;
    cout<<res<<endl ;
    return 0 ;
}