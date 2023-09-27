#include <bits/stdc++.h>
using namespace std ;

/*
https://www.youtube.com/watch?v=g_1qUIlpuzg&t=614s
*/

/*
Example in the above video helps you in understanding better just basically calculating the topological sort and counting the number of ways
its somewhat like number of ways.
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    int timer ;
    vector<bool> visited ;
    vector<int> out ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        timer = 0 ;
        visited.resize(n, false) ;
        out.resize(n, 0) ;
    }

    void add(int a, int b){
        adjlist[a-1].push_back(b) ;
    }

    void dfs(int src, stack<int> &st){
        if(visited[src-1]){
            return ;
        }
        visited[src-1] = true ;
        int size = adjlist[src-1].size() ;
        for(int i = 0 ; i < size ;i++){
            dfs(adjlist[src-1][i], st) ;
        }
        out[src-1] = timer++ ;
        st.push(src) ;
    }
    void solve(){
        stack<int> st ;
        dfs(1, st) ;
        vector<int> ways(vertices, 0) ;
        int mod = 1e9+7 ;
        ways[0] = 1 ;
        while(!st.empty()){
            int top = st.top() ;
            st.pop() ;
            int size = adjlist[top-1].size() ;
            for(int i = 0 ; i < size ; i++){
                ways[adjlist[top-1][i]-1] = (ways[adjlist[top-1][i]-1] + ways[top-1])%mod ;
            }
        }
        cout<<ways[vertices-1]<<endl ;
    }
    // tle 
    void dfs_first(){
        int mod = 1e9 + 7 ;
        int ans = 0 ;
        stack<int> st ;
        st.push(1) ;
        int top  = 0 ; 
        int size = 0 ;
        while(!st.empty()){
            top = st.top() ;
            st.pop() ;
            size = adjlist[top-1].size() ;
            for(int i = 0 ; i < size ; i++){
                if(adjlist[top-1][i] != vertices){
                    st.push(adjlist[top-1][i]) ;
                }
                else{
                    ans = (ans+1)%mod ;
                }
            }
        }
        cout<<ans<<endl ;
    } 

};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    int m = 0 ;
    cin>>n>>m ;
    graph g(n) ;
    int src = 0, dest = 0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src, dest) ;
    }

    // g.dfs_first() ;
    // // int ans= 0 ;
    // // g.solve(ans, 1) ;
    // // cout<<ans<<endl ;
    g.solve() ;

    return 0 ;
}