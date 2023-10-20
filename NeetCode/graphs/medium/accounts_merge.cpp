#include <bits/stdc++.h>
using namespace std ;

/*
https://leetcode.com/problems/accounts-merge/
*/
class disjoint_set{
    vector<int> parent ;
    vector<int> rank ;
    int vertices ;
    public:
    disjoint_set(int n){
        vertices = n ;
        parent.resize(n, -1) ;
        rank.resize(n, 1) ;
        for(int i = 0 ; i < n ; i++){
            parent[i] = i ;
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
        u = find_set(u) ;
        v = find_set(v) ;
        if(u != v){
            if(rank[u] < rank[v]){
                swap(u, v) ;
            }
            parent[v] = u ;
            rank[u] += rank[v] ;
        }
    }

    vector<vector<string>> solve(map<string, pair<string, int>> &mp1, map<int, string> &mp2){
        vector<bool> visited(vertices, false) ;
        vector<vector<string>> ans ;
        int count = 0 ;
        for(int i = 0 ; i < vertices ; i++){
            if(!visited[i]){
                string name = mp1[mp2[i]].first ;
                ans.emplace_back() ;
                ans[count].push_back(name) ;
                ans[count].push_back(mp2[i]) ;
                for(int j = i+1 ; j < vertices ; j++){
                    if(!visited[j] && find_set(i) == find_set(j)){
                        ans[count].push_back(mp2[j]) ;
                        visited[j] = true ; 
                    }
                }
                cout<<endl ;
                sort(ans[count].begin()+1, ans[count].end()) ;
                count++ ;
                visited[i] = true ;
            }
        }
        return ans ;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int count = 0 ;
        int m = accounts.size() ;
        map<string, pair<string, int>> mp1 ;
        map<int, string> mp2 ;
        for(int i = 0 ; i < m ; i++){
            int size = accounts[i].size() ;
            for(int j = 1 ; j < size ; j++){
                if(mp1.find(accounts[i][j]) == mp1.end()){
                    mp1.insert({accounts[i][j], {accounts[i][0], count}}) ;
                    mp2.insert({count, accounts[i][j]}) ;
                    count++ ;
                }
            }
        }
        cout<<count<<endl ;
        disjoint_set dsu(count) ; 
        for(int i = 0 ; i < m ; i++){
            int size = accounts[i].size() ;
            for(int j = 2 ; j < size ; j++){
                if(dsu.find_set(mp1[accounts[i][j-1]].second) != dsu.find_set(mp1[accounts[i][j]].second)){
                    dsu.union_sets(mp1[accounts[i][j-1]].second, mp1[accounts[i][j]].second) ;
                }
            }
        }
        vector<vector<string>> ans = dsu.solve(mp1, mp2) ;
        return ans ;
    }
};

/*
I have a map with one mapping from email to a unique integer and its user name and another mapping integer to the unique mail 
so I am connecting the emails as connected components so if find_set is not same but they are in the same user vector we unite them
later when finding the final result at line no 52 we should not check if parent[j] == parent[i] it is wrong as parent might not contain the actual 
parent we have to check whether they belong to the same set or not.if yes add it 
note I have used emplace back and sroted from .begin()+1 to .end() they told us to sort the emails and name should be the first element in the vector
*/