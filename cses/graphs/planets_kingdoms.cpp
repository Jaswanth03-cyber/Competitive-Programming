#include <bits/stdc++.h>
using namespace std ;

/*
Taking the topological and sort and for now in the revdfs for every unvisited vertex we do a dfs and now after every dfs we will get a strong
connected components and and for every planet in that we assign a kingdom, which I have sent as a parameter as a parent and for every vertex in the 
parameter I am making the parent[node] as the kingdom. 
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<vector<int>> revlist ;
    vector<bool> visited ;
    vector<int> parent ;
    vector<bool> revisited ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        revlist.resize(n) ;
        visited.resize(n, false) ;
        revisited.resize(n, false) ;
        parent.resize(n, 0) ;
    }

    void add(int src, int dest){
        adjlist[src-1].push_back(dest-1) ;
        revlist[dest-1].push_back(src-1) ;
    }

    void dfs(int src, stack<int> &st){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            dfs(node,st) ;
        }
        st.push(src) ;
    }
    void revdfs(int src, int kingdom){
        if(revisited[src]){
            return ;
        }
        revisited[src] = true ;
        parent[src] = kingdom ;
        int size = revlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = revlist[src][i] ;
            revdfs(node,kingdom) ;
        }
    }

    void solve(){
        stack<int> st ;
        for(int i = 0 ; i < vertices ; i++){
            if(!visited[i]){
                dfs(i, st) ;
            }
        }
        int count = 0 ;
        int k = 1 ;
        while(!st.empty()){
            int top = st.top() ;
            st.pop() ;
            if(revisited[top]){
                continue ;
            }
            count++ ;
            revdfs(top, k) ;
            k++ ;
        } 
        cout<<count<<endl ;
        for(int i = 0 ; i < vertices ; i++){
            cout<<parent[i]<<" " ;
        }
        cout<<endl ;
    }
};

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0;
    cin>>n ;
    graph g(n) ;
    int m = 0 ;
    cin>>m  ;
    int src, dest ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src, dest) ;
    }

    g.solve() ;
}