#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
*/


class graph{
    vector<vector<int>> adjlist ;
    vector<int> dp ;
    vector<int> mp ;
    public:
    graph(int n){
        adjlist.resize(n) ;
        dp.resize(n, 0) ;
        mp.resize(26, 0) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs(int src, int parent, string &labels){
        int size = adjlist[src].size() ;
        int count = mp[labels[src] - 'a'] ;
        mp[labels[src]-'a']++ ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            dfs(node, src, labels) ;
        }
        dp[src] = mp[labels[src]-'a'] - count ;
    }

    vector<int> solve(string &labels){
        dfs(0, 0, labels) ;
        return dp ;
    }
};
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        graph g(n) ;    
        for(int i = 0 ; i < n-1 ; i++){
            g.add(edges[i][0], edges[i][1]) ;
        }

        vector<int> ans = g.solve(labels) ;
        return ans ; 
    }
};

/*
use &labels while passing string as many calls so every time it is added to the stack takes lot of space 
*/