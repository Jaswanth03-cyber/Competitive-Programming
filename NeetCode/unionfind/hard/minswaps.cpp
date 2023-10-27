#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/couples-holding-hands/
*/
class disjoint_set{
    int vertices ;
    vector<int> parent ;
    vector<int> rank ;
    public:
    disjoint_set(int n){
        vertices = n ;
        parent.resize(n, -1) ;
        rank.resize(n, -1) ;
    }

    void make_set(int u){
        parent[u] = u ;
        rank[u] = 1 ;
    }

    void preprocess(){
        for(int i = 0 ; i < vertices ; i++){
            make_set(i) ;
        }
    }

    int find_set(int u){
        if(parent[u] == u){
            return u ;
        }
        parent[u] = find_set(parent[u]) ;
        return parent[u] ;
    }

    void union_sets(int u, int v){
        int a = find_set(u) ;
        int b = find_set(v) ;
        if(a != b){
            if(rank[a] < rank[b]){
                swap(a, b) ;
            }
            parent[b] = a ;
            rank[a] += rank[b] ;
        }
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() ;  
        disjoint_set dsu(n) ;
        dsu.preprocess() ;
        for(int i = 0 ; i < n ; i = i+2){
            dsu.union_sets(i, i+1) ;
        }  
        int count = 0 ;
        for(int i = 0 ; i < n ; i = i+2){
            int a = dsu.find_set(row[i]) ;
            int b = dsu.find_set(row[i+1]) ;
            if(a != b){
                dsu.union_sets(a, b) ;
                count++ ;
            }
        }
        return count ;
    }
};

/*
think logically this is somewhat like swaps to get minimum number of swaps if 3 pairs belong to same group we might need only 
1/2 swaps.
*/