#include <bits/stdc++.h>
using namespace std ;

/*
dfs obv works faster and even bfs works but larger vertices dfs works we can even do this in a different way by takign edges as -1 and finding the 
shortest path as given there are no cycles which means we will not have -ve cycles to so we can use dijkstra.
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