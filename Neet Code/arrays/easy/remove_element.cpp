#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/remove-element/
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == val){
                nums[i] = 100 ;
                count++ ;
            }
        } 
        sort(nums.begin(), nums.end()) ;
        return nums.size() - count ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n = 0 ;
    cin>>n ; 
    int val = 0 ;
    cin>>val ;

    vector<int> nums(n,0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i] ;
    }

    Solution ans ;
    int result = ans.removeElement(nums,val) ;

    for(int i = 0 ; i < result ; i++){
        cout<<nums[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}