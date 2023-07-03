#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/squares-of-a-sorted-array/
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq  ;
        vector<int> ans ;
        for(int i = 0 ; i < nums.size() ; i++){
            pq.push(nums[i]*nums[i]) ;
        }
        while(!pq.empty()){
            ans.push_back(pq.top()) ;
            pq.pop() ;
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
    vector<int> result = ans.sortedSquares(nums) ;

    for(int i = 0 ; i < n ; i++){
        cout<<result[i]<<" " ;
    }
    cout<<endl ;
    return 0 ;
}