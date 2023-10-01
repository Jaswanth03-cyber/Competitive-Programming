#include <bits/stdc++.h>
using namespace std ;

/*
actually to calculate MST we take any vertex and take the minimum edge every time and form the minimum spanning tree 

so now we do slightly a different way we have a adjacency matrix so now for every vertex we maintain a struct 

so initially we take a vertex as starting vertex and set its weight to 0 and to as -1 now this is selected vertex 
for every not selected vertex we find the minimum weight of for this vertex from selected vertices that is what we are doing now when a
vertex is selected for all the vertices that are adjacent to this vertices we update min_edge[to].weight of this 

so at the end min_edge(n) we will have, in the spanning tree to which edge these are connected and weights of the edges are there

https://cp-algorithms.com/graph/mst_prim.html

for dense graphs

we can get maximum spanning tree by just replacing the edges with negative weights 
*/
struct edge{
    int weight ;
    int to ;
};

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        for(int i = 0 ; i < n ; i++){
            adjlist[i].resize(n, 0) ;
        }
    }

    void add(int src, int dest, long long weight){
        adjlist[src-1][dest-1] = weight ;
        adjlist[dest-1][src-1] = weight ;
    }

    void solve(){
        vector<bool> visited(vertices, false) ;
        long long ans = 0 ;
        vector<edge> min_edge(vertices) ;
        for(int i = 0 ; i < vertices ; i++){
            min_edge[i].weight = INT_MAX ;
            min_edge[i].to = -1 ;
        }

        min_edge[0].weight = 0 ;   // initially we are selecting this vertex as the starting so making it 0.
        for(int i = 0 ; i < vertices ; i++){
            int v = -1 ;
            for(int j = 0 ; j < vertices ; j++){
                if(!visited[j] && (v == -1 || min_edge[j].weight < min_edge[v].weight)){ // v == -1 as not yet selected || other to take the min of all the weight
                    v = j ;
                }
            }

            if(min_edge[v].weight == INT_MAX){
                cout<<"No MST"<<endl ;
                return ;
            }

            visited[v] = true ;
            ans = ans + min_edge[v].weight ;
            for(int to = 0 ; to < vertices ; to++){
                if(adj[v][to] < min_edge[to].weight){
                    min_edge[to].weight = adj[v][to] ;
                    min_edge[to].to = v ;
                }
            }

        }
        for(int i = 1 ; i < vertices ; i++){
            cout<<"( "i<<", "<<min_edge[i].to<<" )"<<" " ;
        }
        cout<<endl ;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    int m = 0 ;
    cin>>m ;

    graph g(n) ;
    int src = 0, dest = 0 ;
    long long weight ;
    cin>>src>>dest ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest>>weight ;
        g.add(src, dest, weight) ;
    }

    g.solve() ;
    return 0 ;
}