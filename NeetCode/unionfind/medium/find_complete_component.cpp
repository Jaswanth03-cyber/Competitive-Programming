#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/count-the-number-of-complete-components/
*/

class disjoint_set{
    int vertices ;
    vector<int> parent ;
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
        if(u == parent[u]){
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
            parent[b] = a;
            rank[a] += rank[b] ;
        }
    }

    int rankcomp(int u){
        int a = find_set(u) ;
        return rank[a] ;
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        disjoint_set dsu(n) ;
        dsu.preprocess() ;
        int m = edges.size() ;
        for(int i = 0 ; i < m ; i++){
            dsu.union_sets(edges[i][0], edges[i][1]) ;
        } 

        unordered_map<int, pair<int, int>> mp ;
        for(int i = 0 ; i < n ; i++){
            int parent = dsu.find_set(i) ;
            if(mp.find(parent) == mp.end()){
                int rank = dsu.rankcomp(parent) ;
                mp.insert({parent, {rank, 0}}) ;
            }
        }
        for(int i = 0 ; i < m ; i++){
            int parent = dsu.find_set(edges[i][0]) ;
            mp[parent].second++ ;
        }

        int ans = 0 ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            pair<int, int> curr = it->second ;
            if((curr.first*(curr.first-1))/2 == curr.second){
                ans++ ;
            }
        }
        return ans ;
    }
};

/*
do not forget single components so what I have done is first divided into components next for each component I have an element key value pair
in the map where key is the parent of the component and value is a pair with first one in pair as number of vertices in the component 
and second one as number of edges in the component so noofedges = (n*(n-1))/2 then increase count
*/