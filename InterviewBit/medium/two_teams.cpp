#include <bits/stdc++.h>
using namespace std ;

/*
https://www.interviewbit.com/problems/two-teams/
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
    
    bool is_bipartite(){
        for(int i = 0 ; i < vertices ; i++){
            if(side[i] == -1){
                queue<int> pq ;
                pq.push(i) ;
                
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
int Solution::solve(int A, vector<vector<int> > &B) {
    graph g(A) ;
    int m = B.size() ;
    for(int i = 0 ; i < m ; i++){
        g.add(B[i][0]-1, B[i][1]-1) ;
    }
    
    bool ans = g.is_bipartite() ;
    if(ans){
        return 1 ;
    }
    return 0 ;
}

/*
just checking if the graph is bipartite or not.
*/