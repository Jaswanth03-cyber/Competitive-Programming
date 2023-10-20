#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<vector<int>> dp ;
    int m  ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        m = ceil(log2(n)) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs(int src, int parent){
        if(src != 0){
            dp[src][0] = parent ;
            for(int i = 1 ; i <= m ; i++){
                if(dp[src][i-1] == -1){
                    break ;
                }
                dp[src][i] = dp[dp[src][i-1]][i-1] ;
            }
        }
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            dfs(node, src) ;
        }
    }

    void preprocess(){
        dp.resize(vertices, vector<int>(m+1, -1)) ;
        dfs(0, 0) ;
        dp[0][0] = -1 ;
    } 

    int query(int a, int k){
        int ans = -1 ;
        for(int i = m ; i >= 0 ; i--){
            if(k&(1<<i)){
                if(a == -1){
                    return -1 ;
                }
                a = dp[a][i] ;
            }
        }
        if(a != -1){
            ans = a + 1;
        }
        return ans ;
    }
};
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    graph g(n) ;
    int q = 0 ;
    cin>>q ;
    int dest = 0 ;
    for(int i = 1 ; i <= n-1 ; i++){
        cin>>dest ;
        g.add(dest-1, i) ;
    }
    int a =0, k = 0 ;
    g.preprocess() ;
    for(int i = 0 ; i < q ; i++){
        cin>>a>>k ;
        cout<<g.query(a-1, k)<<" " ;
    }
    cout<<endl ;
    return 0 ;
}