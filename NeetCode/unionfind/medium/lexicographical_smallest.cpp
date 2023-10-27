#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/
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

    void union_sets(int u,  int v){
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int count = 0 ;
        int n = s1.length() ;
        unordered_map<char, int> mp ;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(s1[i]) == mp.end()){
                mp.insert({s1[i], count++}) ;
            }
            if(mp.find(s2[i]) == mp.end()){
                mp.insert({s2[i], count++}) ;
            }
        }

        disjoint_set dsu(count) ;
        dsu.preprocess() ;
        unordered_map<int, vector<char>> components ;
        for(int i = 0 ; i < n ; i++){
            dsu.union_sets(mp[s1[i]], mp[s2[i]]) ;
            int a = dsu.find_set(mp[s1[i]]) ;
            if(components.find(a) != components.end()){
                components[a].push_back(s1[i]) ;
                components[a].push_back(s2[i]) ;
            }
            else{
                vector<char> vec = {s1[i], s2[i]} ;
                components.insert({a, vec}) ;
            }
        }

        for(auto it = components.begin() ; it != components.end() ; it++){
            sort(it->second.begin(), it->second.end(), greater<char>()) ;
        }

        int m = baseStr.length() ;
        string ans = "" ;
        for(int i = 0 ; i < m ; i++){
            if(mp.find(baseStr[i]) == mp.end()){
                ans.push_back(baseStr[i]) ;
                continue ; 
            }
            int a = dsu.find_set(mp[baseStr[i]]) ;
            char curr = components[a].back() ;
            ans.push_back(curr) ;
        }
        return ans ;
    }
};

/*
be carefull sometimes the letter might not be there in the map in those cases keep the same do not change it by default map has 0 
for those characters which are not in the map, so it might give the smallest lexicographical character of which is in the union component of 0
*/