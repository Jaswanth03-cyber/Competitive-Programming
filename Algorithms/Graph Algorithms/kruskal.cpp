#include <bits/stdc++.h>
using namespace std ;

struct edge{
    int src ;
    int dest ;
    int weight ;
    edge(int a, int b, int c){
        src = a ;
        dest = b ;
        weight = c ;
    }

};

struct comp{
    bool operator()(const edge &a, const edge &b) const{
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

    void add(int a, int b, int c){
        edge temp(a,b,c) ;
        edges.push_back(temp) ;
    }

    void solve(){
        vector<int> id(vertices, 0) ;
        for(int i = 0 ; i < vertices ; i++){
            id[i] = i ;
        }

        int cost = 0 ;
        sort(edges.begin(), edges.end(), comp()) ;
        vector<edge> result ;
        int size = edges.size() ;
        for(int i = 0 ; i < size ; i++){
            int src = edges[i].src -1 ;
            int dest = edges[i].dest -1 ;
            int weight = edges[i].weight ;
            if(id[src] != id[dest]){
                result.push_back(edges[i]) ;
                cost = cost + weight ;
                int old_id = id[src] ;
                int new_id = id[dest] ;
                for(int j = 0 ; j < vertices ; j++){
                    if(id[j] == old_id){
                        id[j] = new_id ;
                    }
                }
            }
        }

        int size = result.size() ;
        cout<<"MST weights: "<<cost<<endl ;
        cout<<"Edges are as follows : " ;
        for(int i = 0 ; i < size ; i++){
            cout<<"( "<<result[i].src<<", "<<result[i].dest<<")"<<endl ;
        }
    }
};
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0  ;
    cin>>n ;
    graph g(n) ;
    int m = 0 ;
    cin>>m ;
    int src= 0, dest = 0 ;
    for(int i = 0 ; i < m; i++){
        cin>>src>>dest>>weight ;
        g.add(src, dest, weight) ;
    }

    g.solve() ;
}