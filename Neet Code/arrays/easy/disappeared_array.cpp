/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
*/

#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums){

        vector<bool> check(nums.size(), false) ;
        for(size_t i = 0 ; i < nums.size() ; i++){
            if(!check[nums[i]-1]){
                check[nums[i]-1] = true ;
            }
        } 
        vector<int> ans ;
        int count = 0 ;
        for(size_t i = 0 ; i < nums.size() ; i++){
            if(!check[i]){
                ans.push_back(i+1) ;
                count++ ;
            }
        }
        return ans ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n ; 
    cin>>n ;
    vector<int> arr(n,0) ;

    for(int i = 0 ; i < n ; i++){
        cin>>arr[i] ;
    }

    Solution ans ;
    vector<int> result = ans.findDisappearedNumbers(arr) ;
    for(size_t i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}