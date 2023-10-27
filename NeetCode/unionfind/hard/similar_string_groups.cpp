#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/similar-string-groups/
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

bool check(string s, string t){
    if(s.size() != t.size()){
        return false ;
    }
    int n = s.size() ;
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] != t[i]){
            count++ ;
        }
    }
    if(count == 2 || count == 0){
        return true ;
    }
    return false ;
}
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        map<string, int> mp ;
        int n = strs.size() ;
        int count = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(strs[i]) == mp.end()){
                mp.insert({strs[i], count++ }) ;
            }
        }    
        disjoint_set dsu(count) ;
        dsu.preprocess() ;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(check(strs[i], strs[j])){
                    int a = dsu.find_set(mp[strs[i]]) ;
                    int b = dsu.find_set(mp[strs[j]]) ;
                    if(a != b){
                        dsu.union_sets(a, b) ;
                    }
                }
            }
        }
        set<int> st ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            int a = dsu.find_set(mp[strs[i]]) ;
            st.insert(a) ;
        }
        ans = st.size() ;
        return ans ;
    }
};