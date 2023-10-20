#include <bits/stdc++.h>
using namespace std ;

/*
https://www.interviewbit.com/problems/mother-vertex/
*/

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<bool> visited ;
    vector<bool> revisited ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        visited.resize(n, false) ;
        revisited.resize(n, false) ;
    }
    
    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
    }
    
    void dfs1(int src){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            dfs1(node) ;
        }
    }
    void dfs2(int src, int &count){
        if(revisited[src]){
            return ;
        }
        count++ ;
        revisited[src] = true ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            dfs2(node, count) ;
        }
    }
    
    int solve(){
        int mother = -1 ;
        for(int i = 0 ; i < vertices ; i++){
            if(!visited[i]){
                mother = i ;
                dfs1(i) ;
            }
        }
        int count = 0 ;
        dfs2(mother, count) ;
        if(count == vertices){
            return 1 ;
        }
        return 0 ;
    }
};

int Solution::motherVertex(int A, vector<vector<int> > &B) {
    graph g(A) ;
    int size = B.size() ;
    for(int i = 0 ; i < size ; i++){
        g.add(B[i][0]-1, B[i][1]-1) ;
    } 
    
    int ans = g.solve() ;
    return ans ;
}

/*
so doing for all the vertices and checking for the last vertex whose dfs is done as only it might reach all the vertices so 
again doing dfs if so some non reaching vertex is present then there is no mother vertex, if there is one no second dfs is required 
*/