#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest){
        adjlist[src-1].push_back(dest) ;
        adjlist[dest-1].push_back(src) ;
    }

    int bfs(int src, vector<int> &data, int minreq){
        set<int> st ;
        st.insert(data[src]) ;
        vector<int> visited(vertices, false) ;
        vector<int> distance(vertices, 0) ;
        queue<int> pq ;
        pq.push(src) ;
        int count = 1 ;
        int ans = 0 ;
        visited[src] = true ;
        while(!pq.empty()){
            int top = pq.front() ;
            pq.pop() ;
            int size = adjlist[top].size() ;
            bool stop = false ;
            for(int i = 0 ; i < size ; i++){
                int node = adjlist[top][i] - 1 ;
                if(!visited[node]){
                    visited[node] = true ;
                    distance[node] = distance[top]+1 ;
                    pq.push(node) ;
                    if(count == minreq){
                        stop = true ;
                        break ;
                    }
                    else if(!st.count(data[node])){
                        count++ ;
                        ans = ans + distance[node] ;
                        st.insert(data[node]) ;
                    }
                }
            }
            if(stop){
                break ;
            }
        }
        return ans ;
    }

    void solve(vector<int> &data, int minreq){
        int ans = 0 ;
        for(int i = 0 ; i < vertices ; i++){
            ans = bfs(i, data, minreq) ;
            cout<<ans<<" " ;
        }
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0, m = 0, nooftypes = 0, minreq = 0 ;
    cin>>n>>m>>nooftypes>>minreq ;

    vector<int> data(n, 0) ;
    for(int i = 0 ; i < n ; i++){
        cin>>data[i] ;
    }

    graph g(n) ;
    int src = 0, dest = 0 ;
    for(int i = 0 ; i < m; i++){
        cin>>src>>dest ;
        g.add(src, dest) ;
    }

    g.solve(data, minreq) ;
    return 0 ;
}