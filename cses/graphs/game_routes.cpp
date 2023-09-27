#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    int timer ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        timer = 0 ;
    }

    void add(int a, int b){
        adjlist[a-1].push_back(b) ;
    }
    
    void solve(){

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

    g.dfs_first() ;
    // int ans= 0 ;
    // g.solve(ans, 1) ;
    // cout<<ans<<endl ;

    return 0 ;
}