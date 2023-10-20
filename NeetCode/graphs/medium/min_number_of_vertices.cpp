#include<bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
*/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist ;
        adjlist.resize(n) ;
        int m = edges.size() ;
        for(int i = 0 ; i < m ; i++){
            adjlist[edges[i][1]].push_back(edges[i][0]) ;
        } 
        vector<int> ans ;
        for(int i = 0 ; i < n ; i++){
            if(adjlist[i].size() == 0){
                ans.push_back(i) ;
            }
        }
        return ans ;
    }
};

/*
if there are no indegree vertices for a node then we have to do dfs over there for sure as no node can visit it. 
*/