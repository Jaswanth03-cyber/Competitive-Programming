#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<char> color ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        color.resize(n, 'W') ; 
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
    }
    
    bool dfscycle(int src, stack<int> &st){
        color[src] = 'G' ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(color[node] == 'W'){
                if(dfscycle(node, st)){
                    return true ;
                }
            }
            else if(color[node] == 'G'){
                return true ;
            }
        }
        color[src] = 'B' ;
        st.push(src) ;
        return false ;
    }

    void dfs(int src, int &ans, unordered_map<char, int> &mp, string &colors){
        int size = adjlist[src].size() ;
        mp[colors[src]]++ ;
        ans = max(ans, mp[colors[src]]) ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            dfs(node, ans, mp, colors) ;
        }
        mp[colors[src]]-- ;
    }

    int solve(string &colors){
        int ans = 0 ;
        for(int i = 0 ; i < vertices ; i++){
            if(color[i] == 'W' && dfscycle(i)){
                return -1 ;
            }
        }
        vector<bool> visited(vertices, false) ;
        while(!st.empty()){
            int top = st.top() ;
            st.pop() ;
            unordered_map<char, int> mp ;
            dfs(top, ans, mp, colors) ;
        }
        return ans ;
    }
};
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length() ;
        graph g(n) ;
        int m = edges.size() ;
        for(int i = 0 ; i < m ; i++){
            g.add(edges[i][0], edges[i][1]) ;
        } 
        int ans = g.solve(colors) ;
        return ans ;
    }
};