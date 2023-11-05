#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<bool> visited ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        visited.resize(n, false) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
    }

    void dfs(int src, stack<int> &st){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            dfs(adjlist[src][i], st) ;
        }
        st.push(src) ;
    }

    void solve(){
        stack<int> st ;
        dfs(0,st) ;
        int mod = 1e9 + 7 ;
        vector<int> ways(vertices, 0) ;
        ways[0] = 1 ;
        while(!st.empty()){
            int top = st.top() ;
            st.pop() ;
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i] ;
                ways[node] = (ways[node] + ways[top])%mod ;
            }
        }

        cout<<ways[vertices-1]<<endl ;
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
    graph g(n+1) ;

    int src = 0, dest = 0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src, dest) ;
        for(int j = src +1 ; j < dest ; j++){
            g.add(j, dest) ; // this was an additional one given that from src to dest we can stop at any any bus stop in the middle and go to the dest
        }
    }

    g.solve() ;
    return 0 ;
}