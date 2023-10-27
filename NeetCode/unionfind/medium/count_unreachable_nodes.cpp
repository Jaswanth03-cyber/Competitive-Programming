#include <bits/stdc++.h>
using namespace std ;   

/*
https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
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
            parent[b] =a ;
            rank[a] += rank[b] ;
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        disjoint_set dsu(n) ;
        dsu.preprocess() ;
        long long num = n ;
        long long total = (num*(num-1))/2 ; 
        int m = edges.size() ;
        unordered_map<int, long long> mp ;
        for(int i = 0 ; i < m ; i++){
            dsu.union_sets(edges[i][0], edges[i][1]) ;
        }
        long long negative = 0 ;
        for(int i = 0 ; i < n ; i++){
            int a = dsu.find_set(i) ;
            mp[a]++ ;
        }
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            negative += ((it->second)*(it->second-1))/2 ;
        }
        long long ans = total - negative ;
        return ans ;
    }
};

/*
get negative case if we go with positive case(i.e if you calculate for every node by checking whether next nodes are in same union structure or not)
that will be O(n^2) tle 
*/