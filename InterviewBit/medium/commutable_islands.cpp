#include <bits/stdc++.h>
using namespace std ;

/*
https://www.interviewbit.com/problems/commutable-islands/
*/

class disjoint_set{
    int n ;
    vector<int> parent ;
    vector<int> rank ;
    public:
    disjoint_set(int size){
        n = size ;
        parent.resize(n, -1) ;
        rank.resize(n, -1) ;
    }
    
    void make_set(int v){
        parent[v] = v ;
        rank[v] = 1 ;
    }
    
    int find_set(int v){
        if(parent[v] == v){
            return v ;
        }
        parent[v] = find_set(parent[v]) ;
        return parent[v] ;
    }
    
    void union_sets(int u, int v){
        int a = find_set(u) ;
        int b = find_set(v) ;
        if(rank[a] < rank[b]){
            swap(a, b) ;
        }
        parent[b] = a ;
        rank[a] += rank[b] ;
    }
};

struct comp{
    bool operator()(const vector<int> &a, const vector<int> &b)const{
        if(a[2] < b[2]){
            return true ;
        }
        return false ;
    }
};
int Solution::solve(int A, vector<vector<int> > &B) {
    disjoint_set dsu(A) ;
    for(int i = 0 ; i < A ; i++){
        dsu.make_set(i) ;
    }
    sort(B.begin(), B.end(), comp()) ;
    int m = B.size() ;
    int ans= 0 ;
    for(int i = 0 ; i < m ; i++){
        if(dsu.find_set(B[i][0]-1) != dsu.find_set(B[i][1]-1)){
            ans = ans + B[i][2] ;
            dsu.union_sets(B[i][0]-1, B[i][1]-1) ;
        } 
    }
    return ans ;
}

/*
just mst and also beware of indexing and also just see for vectors you might need that comp() not just comp 
*/