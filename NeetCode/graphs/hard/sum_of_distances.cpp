#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/sum-of-distances-in-tree/
*/

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> dp ;
    vector<int> height ;
    vector<int> subordinates ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        dp.resize(n, 0) ;
        height.resize(n, 0) ;
        subordinates.resize(n, 1) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs1(int src, int parent){
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            height[node] = height[src] + 1 ;
            dp[0] = dp[0] + height[node] ;
            dfs1(node, src) ;
            subordinates[src] = subordinates[src] + subordinates[node] ;
        }
    }

    void dfs2(int src, int parent){
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            dp[node] = dp[src] + vertices - 2*subordinates[node] ;
            dfs2(node, src) ;
        }
    }

    vector<int> solve(){
        dfs1(0, 0) ;
        dfs2(0, 0) ;
        return dp ;
    }
};
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph g(n) ;
        int m = edges.size() ;
        for(int i = 0 ; i < m ; i++){
            g.add(edges[i][0], edges[i][1]) ;
        }
        vector<int> ans = g.solve() ;
        return ans ;
    }
};
