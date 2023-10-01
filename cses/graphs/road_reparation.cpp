#include <bits/stdc++.h>
using namespace std ;


class disjoint_set{
    vector<int> parent ;
    vector<int> rank ;
    public:
    disjoint_set(int n){
        parent.resize(n, -1) ;
        rank.resize(n, -1) ;
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
            if(rank[a] < rank[b]){
                swap(a, b) ;
            }
            parent[b] = a ;
            rank[a] = rank[a] + rank[b] ;
        }
    }
};

struct edge{
    int src ;
    int dest ;
    long long weight ;
    edge(int a, int b, long long c){
        this->src = a ;
        this->dest = b ;
        this->weight = c ;
    }
};

struct comp{
    bool operator()(const edge &a, const edge &b)const{
        return a.weight < b.weight ;
    }
};


class graph{
    int vertices ;
    vector<edge> edges ;
    public:
    graph(int n){
        vertices = n ;
    }

    void add(int src, int dest, long long weight){
        edges.push_back(edge(src-1, dest-1, weight)) ;
    }

    void solve(){
        disjoint_set dsu(vertices) ;
        for(int i = 0 ; i < vertices ; i++){
            dsu.make_set(i) ;
        } 

        sort(edges.begin(), edges.end(), comp()) ;
        int size = edges.size() ;

        long long cost = 0 ;
        int count = 0 ;
        for(int i = 0 ; i < size ; i++){
            int u = dsu.find_set(edges[i].src) ;
            int v = dsu.find_set(edges[i].dest) ;
            if(u != v){
                cost = cost + edges[i].weight ;
                count++ ;
                dsu.union_sets(u, v) ;
            }
        } 
        if(count != vertices -1){
            cout<<"IMPOSSIBLE"<<endl ;
            return ;
        }
        cout<<cost<<endl ;  
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int m = 0 ;

    cin>>n>>m ;
    graph g(n) ;

    int src = 0, dest = 0 ;
    long long weight = 0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest>>weight ;
        g.add(src, dest, weight) ;
    }

    g.solve() ;
    return 0 ;
}