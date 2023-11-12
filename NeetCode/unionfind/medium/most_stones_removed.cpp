#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
*/

class disjoint_set{
    int vertices ;
    vector<int> parent; 
    vector<int> rank ;
    public:
    disjoint_set(int n){
        vertices = n ;
        parent.resize(n) ;
        rank.resize(n) ;
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

    int solve(){
        int ans = 0 ;
        unordered_map<int, int> mp ;
        for(int i = 0 ; i < vertices ; i++){
            int a = find_set(i) ;
            mp[a]++ ;
        }
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            ans += it->second - 1 ;
        }
        return ans ;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size() ;
        disjoint_set dsu(n) ;
        dsu.preprocess() ;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    cout<<i<<" "<<j<<endl ;
                    dsu.union_sets(i, j) ;
                }
            }
        }
        int ans = 0 ;
        ans = dsu.solve() ;
        return ans ; 
    }
};
