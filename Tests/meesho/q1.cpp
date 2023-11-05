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
        if(rank[a] < rank[b]){
            swap(a, b) ;
        }
        parent[b] = a ;
        rank[a] += rank[b] ;
    }
};

struct edge{
    int src ;
    int dest ;
    int weight ;

    edge(int a, int b, int c){
        this->src = a ;
        this->dest = b ;
        this->weight = c ;
    }
};

struct comp{
    bool operator()(const edge &a, const edge &b)const{
        return a.weight >= b.weight ;
    }
};

void solve(){
    int n = 0 ;
    cin>>n ;

    vector<int> arr(n, 0) ;
    for(int i = 0 ; i < n ;  i++){
        cin>>arr[i] ;
    }

    vector<edge> edges ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            edges.push_back(edge(i, j, arr[i]^arr[j])) ;
        }
    }

    sort(edges.begin(), edges.end(), comp()) ;

    int m = edges.size() ;
    disjoint_set dsu(n) ;
    dsu.preprocess() ;
    int ans = 0 ;
    int src=0, dest = 0 ;
    for(int i = 0 ; i < m ; i++){
        src = edges[i].src ;
        dest = edges[i].dest ; 
        int a = dsu.find_set(src) ;
        int b = dsu.find_set(dest) ;
        if(a != b){
            dsu.union_sets(src, dest) ;
            ans += edges[i].weight ;
        }
    }

    cout<<ans<<endl ;
}

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    solve() ;


    return 0 ;
}

/*
given an array of n elements do the following operations n-1 times and you initially have a sum which is 0

select two indices x and y do arr[x]^arr[y] and add the resulting value to sum remove one of x and y so after n-1 operations what is the maximum value of sum you can get
*/