#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/possible-bipartition/
*/

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> side ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        side.resize(n, -1) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    bool solve(){
        for(int i = 0  ; i < vertices ; i++){
            if(side[i] == -1){
                queue<int> pq ;
                pq.push(i) ;
                side[i] = 0 ;
                while(!pq.empty()){
                    int top = pq.front() ;
                    pq.pop() ;
                    int size = adjlist[top].size() ;
                    for(int i = 0 ; i < size ; i++){
                        int node = adjlist[top][i] ;
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

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph g(n) ;   
        int m = dislikes.size() ;
        for(int i = 0 ; i < m ; i++){
            g.add(dislikes[i][0]-1, dislikes[i][1]-1) ;
        }
        bool ans = g.solve() ;
        return ans ; 
    }
};