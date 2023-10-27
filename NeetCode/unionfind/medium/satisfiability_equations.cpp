#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/satisfiability-of-equality-equations/
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
    bool equationsPossible(vector<string>& equations) {
        map<char, int> mp ;
        int count = 0 ;
        int n = equations.size() ;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(equations[i][0]) == mp.end()){
                mp.insert({equations[i][0], count++}) ;
            }
            if(mp.find(equations[i][3]) == mp.end()){
                mp.insert({equations[i][3], count++}) ;
            }
        } 

        disjoint_set dsu(count) ;
        dsu.preprocess() ;
        for(int i = 0 ; i < n ; i++){
            int one = mp[equations[i][0]] ;
            int two = mp[equations[i][3]] ;
            int a = dsu.find_set(one) ;
            int b = dsu.find_set(two) ;
            if(equations[i][1] == '=' && a != b){
                dsu.union_sets(a, b) ;
            }
        } 
        for(int i = 0 ; i < n ; i++){
            int one = mp[equations[i][0]] ;
            int two = mp[equations[i][3]] ;
            int a = dsu.find_set(one) ;
            int b = dsu.find_set(two) ;
            if(equations[i][1] == '!' && a == b){
                return false ;
            }
        } 
        return true ;
    }
};