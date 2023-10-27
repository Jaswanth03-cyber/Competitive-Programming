#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/smallest-string-with-swaps/description/
*/

class disjoint_set{
    int vertices ;
    vector<int> parent ;
    vector<int> rank ;
    public:
    disjoint_set(int n){
        vertices = n ;
        parent.resize(n,-1) ;
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
                swap(a,b) ;
            }
            parent[b] = a ;
            rank[a] += rank[b] ;
        }
    }
};

/*
this is giving tle for last case 
*/
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length() ;
        disjoint_set dsu(n) ;
        dsu.preprocess() ; 
        int m = pairs.size() ;
        for(int i = 0 ; i < m ; i++){
            dsu.union_sets(pairs[i][0], pairs[i][1]) ;
        }  

        vector<bool> visited(n, false) ;
        vector<pair<char, int>> vec ;
        for(int i = 0 ; i < n ; i++){
            vec.push_back({'a', i}) ;
        }
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                vector<char> temp ;
                vector<int> indexes ;
                for(int j = i ; j < n ; j++){
                    int a = dsu.find_set(i) ;
                    int b = dsu.find_set(j) ;
                    if(a == b){
                        temp.push_back(s[j]) ;
                        visited[j] = true ;
                        indexes.push_back(j) ;
                    }
                }
                sort(temp.begin(), temp.end()) ;
                int size = temp.size() ;
                for(int j = 0 ; j < size ; j++){
                    vec[indexes[j]].first = temp[j] ;
                }
            }
        }
        string ans = "" ;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(vec[i].first) ;
        }
        return ans ; 
    }
};

/*
creating a map of components of unon find and storing them in a vector sorting them and assigning at the correct index 
note sorting I have done in reverse order as we can pop from the back only
*/
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length() ;
        disjoint_set dsu(n) ;
        dsu.preprocess() ; 
        int m = pairs.size() ;
        for(int i = 0 ; i < m ; i++){
            dsu.union_sets(pairs[i][0], pairs[i][1]) ;
        }  
        unordered_map<int, vector<char>> mp ;
        for(int i = 0 ; i < n ; i++){
            int a = dsu.find_set(i) ;
            if(mp.find(a) != mp.end()){
                mp[a].push_back(s[i]) ;
            }
            else{
                vector<char> = {s[i]} ;
                mp.insert({a, vec}) ;
            }
        }

        for(auto it = mp.begin() ; it != mp.end() ; it++){
            sort(it->second.begin(), it->second.end(), greater<char>()) ;
        }

        string ans = temp ;
        for(int i = 0 ; i < n ; i++){
            int a = dsu.find_set(i) ;
            ans[i] = mp[a].back() ;
            mp[a].pop_back() ;
        }
        return ans ; 
    }
};