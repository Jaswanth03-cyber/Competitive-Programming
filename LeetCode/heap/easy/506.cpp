#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/relative-ranks/
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size() ;
        vector<string> ans(n, "") ;
        priority_queue<pair<int, int>> pq ;
        for(int i = 0 ; i < n ; i++){
            pq.push({score[i], i}) ;
        }
        int count = 1 ;
        while(!pq.empty()){
            ans[pq.top().second] = to_string(count) ;
            pq.pop() ;
            count++ ;
        }
        for(int i = 0 ; i < n ; i++){
            if(ans[i] == "1"){
                ans[i] = "Gold Medal" ;
            }
            else if(ans[i] == "2"){
                ans[i] = "Silver Medal" ;
            }
            else if(ans[i] == "3"){
                ans[i] = "Bronze Medal" ;
            }
        }
        return ans ;
    }
};