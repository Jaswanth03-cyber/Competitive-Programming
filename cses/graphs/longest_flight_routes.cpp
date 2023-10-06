#include <bits/stdc++.h>
using namespace std ;

/*
https://copyprogramming.com/howto/why-is-topological-sort-needed-for-longest-path-in-directed-acyclic-graph
*/

/*
We can not used modified bfs over here because we do not have an obtimal substructure like in the case of the shortest paths so that will be a problem
so we need a optimal substructure so instead of those we build a topo sort 
*/
/*
dfs obv works faster and even bfs works but larger vertices dfs works we can even do this in a different way by takign edges as -1 and finding the 
shortest path as given there are no cycles which means we will not have -ve cycles to so we can use dijkstra.

this will be a wrong one if 1 and n are not connected if in case they asks maximum distance between two nodes then we have to find the 
topo sort of all the vertices see Atcoder G_Longest Path sum.

here the src is fixed so we have to do dfs from one only. in the above atcoder one there he asked max distance between any two.
so here for sure dfs must start from 1 and check if path exists or not not any path to the last vertex.
*/
class graph{
    int vert ;
    vector<vector<int>> adj ;
    public:
    graph(int n){
        vert = n ;
        adj.resize(n) ;
    }

    void add(int src, int dest){
        adj[src-1].push_back(dest) ;
    }

    void solve(){
        vector<int> dist(vert+1, 0) ;
        vector<int> parent(vert+1, -1) ;
        stack<int> st ;
        st.push(1) ;
        int size = 0 ;
        int top = 0 ;
        while(!st.empty()){
            top = st.top() ;
            st.pop() ;
            size = adj[top-1].size() ;
            for(int i = 0 ; i < size ; i++){
                if(dist[adj[top-1][i]] < dist[top]+1){
                    dist[adj[top-1][i]] = dist[top] + 1 ;
                    st.push(adj[top-1][i]) ;
                    parent[adj[top-1][i]] = top ;
                }
            }
        }
        if(dist[vert] == 0){
            cout<<"IMPOSSIBLE"<<endl ;
        }
        else{
            vector<int> vec ;
            for(int i = vert ; i != -1 ; i = parent[i]){
                vec.push_back(i) ;
            }
            int size = vec.size() ;
            cout<<size<<endl ;
            for(int i = size -1 ; i >=0 ; i--){
                cout<<vec[i]<<" " ;
            }
            cout<<endl ;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;

    graph g(n) ;
    int m = 0 ;
    cin>>m ;

    int src = 0, dest = 0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src, dest) ;
    }

    g.solve() ;
    return 0 ;
}

/*
this is different from high score as high score has weights there we need to use bell man ford as ther can be postive cycles
and also note that here maximum is counted based on number of vertices  visited previously so
this is like in all the possible paths we have to takw the path which has more number of ways so we need to do topological sort foro sure.
*/