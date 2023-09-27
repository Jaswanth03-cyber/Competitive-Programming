#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    int timer ;
    vector<int> out ;
    vector<bool> visited ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        timer = 0 ;
        out.resize(n, 0) ;
        visited.resize(n, false) ;
    }

    void add(int src, int dest){
        adjlist[src-1].push_back(dest) ;
    }

    void dfs(int src){
        if(visited[src-1]){
            return ;
        }
        visited[src-1] = true ;
        timer++ ;
        int size = adjlist[src-1].size() ;
        for(int i = 0 ; i < size ; i++){
            dfs(adjlist[src-1][i]) ;
        }
        out[src-1] = timer++ ;
        // st.push(src) ;
        return ;
    }

    void solve(){
        dfs(1) ;
        vector<pair<int, int>> topo ;
        for(int i = 0 ; i < vertices ; i++){
            topo.push_back({out[i], i}) ;
        }
        sort(topo.begin(), topo.end()) ;
        stack<int> st ;
        // dfs(1, st) ;
        for(int i = 0 ; i < vertices; i++){
            st.push(topo[i].second+1) ;
        }
        vector<int> dis(vertices, INT_MIN) ;
        vector<int> parent(vertices, -1) ;
        int top = 0 ;
        dis[0] = 0 ;
        while(!st.empty()){
            top = st.top() ;
            st.pop() ;
            int size = adjlist[top-1].size() ;
            for(int i = 0 ; i < size; i++){
                if(dis[top-1] != INT_MIN){
                    if(dis[top-1]+1 > dis[adjlist[top-1][i]-1]){
                        dis[adjlist[top-1][i]-1] = dis[top-1]+1 ;
                        parent[adjlist[top-1][i]-1] = top-1 ;
                    }
                }
            }
        }
        if(dis[vertices-1] != INT_MIN){
            cout<<dis[vertices-1]+1<<endl ;
            vector<int> path ;
            for(int i = vertices - 1; i != -1 ; i = parent[i]){
                path.push_back(i+1) ;
            }
            int size = path.size() ;
            for(int i = size -1 ; i >= 0 ; i--){
                cout<<path[i]<<" " ;
            }
            cout<<endl ;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl ;
        }
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

    int src, dest ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src, dest) ;
    }
    g.solve() ;
    return 0 ;
}