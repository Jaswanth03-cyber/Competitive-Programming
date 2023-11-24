#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/path-with-minimum-effort/description/
*/
typedef pair<int, int> pi ;
typedef pair<int, pi> pii ;
struct comp{
    bool operator()(const pii &a, const pii &b)const{
        return a.first < b.first ;
    }
}; // this is not at all required can just write greatre thats all 
/*
be carefull in max and mean heap these comp functions work different(reverse order sorting)
*/
class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<vector<int>> heights){
        priority_queue<pii, vector<pii>, comp> pq ;
        pq.push({0, {0, 0}}) ;
        int n = heights.size()  ; 
        int m = heights[0].size() ;
        dp[0][0] = 0 ;
        while(!pq.empty()){
            int curr = pq.top().first ;
            int x = pq.top().second.first ;
            int y = pq.top().second.second ;
            pq.pop() ;
            if(curr > dp[x][y]){
                continue ;
            }
            int value = 0 ;
            if(x != 0){
                value = max(curr, abs(heights[x-1][y] - heights[x][y])) ;
                if(dp[x-1][y] > value){
                    pq.push({value, {x-1, y}}) ;
                    dp[x-1][y] = value ;
                }  
            }
            if(x != n-1){
                value = max(curr, abs(heights[x+1][y] - heights[x][y])) ;
                if(dp[x+1][y] > value){
                    pq.push({value, {x+1, y}}) ;
                    dp[x+1][y] = value ;
                }  
            }
            if(y != 0){
                value = max(curr, abs(heights[x][y-1] - heights[x][y])) ;
                if(dp[x][y-1] > value){
                    pq.push({value, {x, y-1}}) ;
                    dp[x][y-1] = value ;
                }
            }
            if(y != m-1){
                value = max(curr, abs(heights[x][y+1] - heights[x][y])) ;
                if(dp[x][y+1] > value){
                    pq.push({value, {x, y+1}}) ;
                    dp[x][y+1] = value ;
                }
            }
        }
        return dp[n-1][m-1] ;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() ;
        int m = heights[0].size() ;

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX)) ;
        int ans = solve(dp, heights) ; 
        return ans ;   
    }
};