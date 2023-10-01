#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/is-graph-bipartite/
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int> side(n, -1) ;
        for(int i = 0 ; i < n ; i++){
            if(side[i] == -1){
                queue<int> pq ;
                pq.push(i) ;
                side[i] = 0 ;  
                while(!pq.empty()){
                    int top = pq.front() ;
                    pq.pop() ;
                    int size = graph[top].size() ;
                    for(int j = 0 ; j < size ; j++){
                        int node = graph[top][j] ;
                        if(side[node] == -1){
                            side[node] = side[top]^1 ;
                            pq.push(node) ;
                        }
                        else if(side[node] == side[top]){
                            return false ;
                        }
                    }
                }
            }
        }
        return true ; 
    }
};