#include <bits/stdc++.h>
using namespace std ;

// disjoint union set can not be used when a graph is directed to find number of components.

/*
whenever there is a union we are decreasing the count initally there are n groups every time there is a union we will decrease one and
when there is a union there can be chance for chaning the large one so chaning it at the same time as seperate chaning is resulting in tle
*/
class disjoint_set{
    vector<int> parent ;
    vector<int> rank ;
    int count ;
    int large ;
    public:
    disjoint_set(int n){
        parent.resize(n, -1) ;
        rank.resize(n, -1) ;
        count = n ;
        large = 1 ;
    }

    void make_set(int v){
        parent[v] = v;
        rank[v] = 1 ;
    }

    int find_set(int v){
        if(v == parent[v]){
            return v ;
        }
        parent[v] = find_set(parent[v]) ;
        return parent[v] ;
    }

    void union_sets(int u, int v){
        int a = find_set(u) ;
        int b = find_set(v) ;

        if(a != b){
            count-- ;
            if(rank[a] < rank[b]){
                swap(a, b) ;
            }
            parent[b] = a ;
            rank[a] += rank[b] ;
            large = max(large, rank[a]) ;
        }
    }

    void solve(int a, int b){
        cout<<count<<" "<<large<<endl ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int m = 0 ;
    cin>>n>>m ;

    disjoint_set graph(n) ;
    for(int i = 0 ; i < n ; i++){
        graph.make_set(i) ;
    }
    int src = 0, dest = 0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        graph.union_sets(src-1, dest-1) ;
        graph.solve(src-1, dest-1) ;
    } 

}