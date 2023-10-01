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
        adjlist[src-1].push_back(dest) ;
    }

    void dfs(int src, stack<int> &st){
        if(visited[src-1]){
            return ;
        }
        visited[src-1] = true ;
        int size = adjlist[src-1].size() ;
        for(int i = 0 ; i < size ; i++){
            dfs(adjlist[src-1][i], st) ;
        }
        st.push(src) ;
    }

    void solve(){
        stack<int> st ;
        for(int i = 0 ; i < vertices ; i++){
            if(!visited[i]){
                dfs(i+1, st) ;
            }
        }
        vector<int> dis(vertices, 0) ;
        int top = 0 ;
        while(!st.empty()){
            top = st.top() ;
            st.pop() ;
            int size = adjlist[top-1].size() ;
            for(int i = 0 ; i < size ; i++){
                if(dis[adjlist[top-1][i]-1] < dis[top-1]+1){
                    dis[adjlist[top-1][i]-1] = dis[top-1]+1 ;
                }
            }
        }
        int ans = *max_element(dis.begin(), dis.end()) ;
        cout<<ans<<endl ;
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