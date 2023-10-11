#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> parent ;
    vector<int> children ;
    vector<int> depth ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        parent.resize(n, 0) ;
        children.resize(n, 0) ;
        depth.resize(n, 0) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs(int src, int parent){
        int size = adjlist[src].size() ;
        children[src] = 1 ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            parent[node] = src ;
            depth[node] = depth[src] + 1 ;
            if(node != parent){
                dfs(node, src) ;
            }
            children[src] += children[node] ;  //children[node]-1 will be the count of number of children 
        }
    }

    void solve(){
        // this stack can also be used to compute number of children this function is just an example how we can use stack also to solve child queries
        vector<int> data(vertices, 0) ;
        queue<int> pq ;
        pq.push(0) ;
        stack<pair<int, int>> st ;
        while(!pq.empty()){
            int top = pq.top() ;
            pq.pop() ;
            int size = adjlist[top].size() ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i] ;
                if(!visited[node]){
                    visited[node] = true ;
                    pq.push(node) ;
                    st.push({node, top}) ;
                }
            }
        }
        vector<int> value(vertices, 1) ;
        while(!st.empty()){
            data[st.top().second] += data[st.top().first] + value[st.top().first] ;
            st.pop() ;
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
    int src, dest ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src, dest) ;
    }

    g.dfs(0, 0) ;

    return 0 ;
}