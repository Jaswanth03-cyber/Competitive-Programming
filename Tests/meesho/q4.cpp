#include <bits/stdc++.h>
using namespace std ;


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
            parent[b] = a ;
            rank[a] += rank[b] ;
        }
    }

    int returnrank(int u){
        int a = find_set(u) ;
        return rank[a] ;
    }
};

void solve(){
    int n = 0 ;
    cin>>n ;

    disjoint_set dsu(n) ;
    dsu.preprocess() ;
    int m = 0 ;
    cin>>m ;
    int src =0. dest = 0 ;

    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        dsu.union_sets(src-1, dest-1) ;
    } 

    int k = 0 ;
    cin>>k ;
    for(int i = 0 ; i < k ;i++){
        cin>>src ;
        cout<<dsu.returnrank(src)<<endl ; 
    }
}
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;
    return 0 ;
}