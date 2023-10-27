#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/number-of-good-paths/
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

    void make_set(int i){
        parent[i] = i ;
        rank[i] = 1 ;
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
            rank[a] += rank[b] ;
            parent[b] = a ;
        }
    }

};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size() ;
        int m = edges.size() ;
        map<int, vector<int>> mp ;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(vals[i]) != mp.end()){
                mp[vals[i]].push_back(i) ; 
            }
            else{
                vector<int> vec = {i} ;
                mp.insert({vals[i], vec}) ;
            }
        }
        disjoint_set dsu(n) ;
        dsu.preprocess() ;
        vector<vector<int>> adjlist ;
        adjlist.resize(n) ;
        for(int i = 0 ; i < m ; i++){
            adjlist[edges[i][0]].push_back(edges[i][1]) ;
            adjlist[edges[i][1]].push_back(edges[i][0]) ;
        }
        int ans = 0 ;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            int size = it->second.size() ;
            for(int i = 0 ; i < size ; i++){
                int src = it->second[i] ;
                int neighbors = adjlist[src].size() ;
                for(int j = 0 ; j < neighbors ; j++){
                    int node = adjlist[src][j] ;
                    if(vals[node] <= vals[src]){
                        dsu.union_sets(node, src) ;
                    }
                }
            }
            map<int, int> count ;
            for(int i = 0 ; i < size ; i++){
                count[dsu.find_set(it->second[i])]++ ;
            }
            ans = ans + size ;
            for(auto it1 = count.begin() ; it1 != count.end() ; it1++){
                ans = ans + ((it1->second)*(it1->second -1))/2 ;
            }
        }

        return ans ;
    }
};

/*
so what is that we are doing is that first noting all the nodes that have the same value in a map with node value as the key and vector of nodes 
whose value is same, so now for each value and now for each node in the vector we visit the neighbouring nodes whose value is <= to the node value 
if so yes then we combine both of them now after for all the nodes of the same value we have created a disjoint union trees 
here if a union tree contain x pairs which are having same value then xc2 is number of paths so inside the for loop of same value 
we are checking to which union find tree a node belongs to if three nodes of same value belong to same union find then 6 paths


note that computation of ans and ans + ((it1))... this is all should be done inside that loop itself not after computing all the disjoint set trees
as for example in the example 1 after all computations all the nodes will be connected now both the nodes of the value will belong to the
same component so we thing that there is a path between them but that is not a valid path as you will get 1-2-1 thats wrong so before computing for 
all values after the preprocessing of each value itself you complete number of nodes in a disjoint tree.
*/