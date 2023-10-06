#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/detonate-the-maximum-bombs/
*/
/*
so to comppare float values is difficult so we took long long by not applying sqrt and have computed it that way 
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
    }

    void dfs(int src, int &count, vector<bool> &visited){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        count++ ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            dfs(node, count, visited) ;
        }
    }
};
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size() ;
        graph g(n) ;
        for(int i = 0 ; i < n ; i++){
            long long x = bombs[i][0], y = bombs[i][1], r = bombs[i][2] ; 
            for(int j = 0; j < n ; j++){
                if(i != j){
                    long long diff_x = abs(x-bombs[j][0]), diff_y = abs(y-bombs[j][1]) ;
                    if(diff_x*diff_x + diff_y*diff_y <= r*r){
                        g.add(i, j) ;
                    }
                }
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            vector<bool> visited(n, false) ;
            int count = 0 ;
            g.dfs(i, count, visited) ;
            ans = max(ans, count) ;
        }
        return ans ;
    }
};