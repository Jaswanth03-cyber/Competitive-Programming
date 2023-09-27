#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/all-paths-from-source-to-target/
*/

class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &temp, int src, vector<vector<int>> &graph, int n){
        int size = graph[src-1].size() ;
        for(int i = 0 ; i < size ; i++){
            if(graph[src-1][i] == n -1){
                temp.push_back(n-1) ;
                ans.push_back(temp) ;
                temp.pop_back() ;
            }
            else {
                temp.push_back(graph[src-1][i]) ;
                dfs(ans, temp, graph[src-1][i]+1, graph, n) ;
                temp.pop_back() ;
            }
        }
        return ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<vector<int>> ans ;
        vector<int> temp ;
        temp.push_back(0) ;
        dfs(ans, temp, 1, graph, n) ;
        return ans ; 
    }
};