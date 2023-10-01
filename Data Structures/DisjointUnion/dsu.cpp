#include <bits/stdc++.h>
using namespace std ;

// this is just making a tree for a node wwe are maintaining its parent and also size of each tree
class disjoint_set{
    vector<int> parent ;
    vector<int> rank ;
    public:
    disjoint_set(int n){
        parent.resize(n, -1) ;
        rank.resize(n, -1) ;
    }

    void make_set(int v){
        parent[v] = v;
        rank[v] = 1 ;
    }

    int find_set(int v){
        if(v == parent[v]){
            return v ;
        }
        parent[v] = find_set(parent[v]) ;
        return parent[v] ;
    }
    void union_sets(int u, int v){
        int a = find_set(u) ;
        int b = find_set(v) ;
        if(a != b){
            if(rank[a] < rank[b]){
                swap(a, b) ;
            }
            parent[b] = a ;
            rank[a] = rank[a] + rank[b] ;
        }
    }
};