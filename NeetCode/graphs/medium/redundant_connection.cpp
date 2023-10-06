#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/redundant-connection/
*/

/*
first checking if first n-1 edges are sufficient then just return last edge otherwise add the last edge and now from i = n-2 till 0 
remove edge if fo an edge all nodes are visited then no need of that esge
*/
class graph{
    int vertices ;
    vector<set<int>> adjlist ;
    vector<bool> visited ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        visited.resize(n, false) ;
    }

    void add(int src, int dest){
        adjlist[src].insert(dest) ;
        adjlist[dest].insert(src) ;
    }

    void dfs(int src, int &count){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        count++ ;
        // cout<<src<<" "<<count<<endl ;
        for(auto it = adjlist[src].begin() ; it != adjlist[src].end() ; it++){
            int node = *it ;
            dfs(node, count) ;
        }
    }

    void reset(){
        fill(visited.begin(), visited.end(), false) ;
    }

    void remove(int src, int dest){
        adjlist[src].erase(adjlist[src].find(dest)) ;
        adjlist[dest].erase(adjlist[dest].find(src)) ;
    }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        graph g(n) ; 
        for(int i = 0 ; i < n - 1 ; i++){
            g.add(edges[i][0]-1, edges[i][1]-1) ;
        }
        int count = 0 ;
        g.dfs(0, count) ;
        if(count == n){
            return edges[n-1] ;
        }
        vector<int> ans ;
        g.add(edges[n-1][0]-1, edges[n-1][1]-1) ;
        g.reset() ;
        for(int i = n-2 ; i >= 0 ; i--){
            count = 0 ;
            g.remove(edges[i][0]-1, edges[i][1]-1) ;
            g.dfs(0, count) ;
            // cout<<count<<" "<<edges[i][0]<<" "<<edges[i][1]<<endl ;
            if(count == n){
                ans = edges[i] ;
                break ;
            }
            g.add(edges[i][0]-1, edges[i][1]-1) ;
            g.reset() ;
        }
        return ans ;
    }
};