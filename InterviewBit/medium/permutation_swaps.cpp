#include <bits/stdc++.h>
using namespace std ;

/*
https://www.interviewbit.com/problems/permutation-swaps/
*/
class disjoint_set{
    int n ;
    vector<int> parent ;
    vector<int> rank ;
    public:
    disjoint_set(int size){
        n = size ;
        parent.resize(n, -1) ;
        rank.resize(n, -1) ;
    }
    
    void make_set(int v){
        parent[v] = v ;
        rank[v] = 1 ;
    }
    void preprocess(){
        for(int i = 0 ; i < n ; i++){
            make_set(i) ;
        }
    }
    int find_set(int v){
        if(parent[v] == v){
            return v ;
        }
        parent[v] = find_set(parent[v]) ;
        return parent[v] ;
    }
    
    void union_sets(int u, int v){
        int a = find_set(u) ;
        int b = find_set(v) ;
        if(rank[a] < rank[b]){
            swap(a, b) ;
        }
        parent[b] = a ;
        rank[a] += rank[b] ;
    }
};
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size() ;
    disjoint_set dsu(n) ; 
    dsu.preprocess() ;
    int m = C.size() ;
    for(int i = 0 ; i < m ; i++){
        if(dsu.find_set(A[C[i][0]-1] - 1) != dsu.find_set(A[C[i][1]-1] - 1)){
            dsu.union_sets(A[C[i][0]-1]-1, A[C[i][1]-1]-1) ;
        }
    }
    
    for(int i = 0 ; i < m ; i++){
        if(dsu.find_set(B[C[i][0]-1] - 1) != dsu.find_set(B[C[i][1]-1] - 1)){
            return 0 ;
        }
    }
    return 1 ;
}

/*
so using the matrix C we are creating a graph with values of A as vertices, so now with this we check if B at the same indices
belong to the same components or not if they are not belonging to the same components then irrespective of how many swaps we do we can not build A 
from B beware of indexing.
*/
