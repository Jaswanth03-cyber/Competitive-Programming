#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/height-checker/
*/

class Solution {
public:
    int heightChecker(vector<int>& heights){ 
        priority_queue<int, vector<int>, greater<int>> pq ;
        for(int i = 0 ; i < heights.size() ; i++){
            pq.push(heights[i]) ;
        }
        vector<int> expected ;
        while(!pq.empty()){
            expected.push_back(pq.top()) ;
            pq.pop() ;
        }
        int ans = 0 ;
        for(int i = 0 ; i < heights.size(); i++){
            if(expected[i] != heights[i]){
                ans++ ;
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

    vector<int> heights(n,0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>heights[i] ;
    }

    Solution ans ;
    int result = ans.heightChecker(heights) ;
    cout<<result<<endl ;
    return 0 ; 
}