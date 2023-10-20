#include <bits/stdc++.h>
using namespace std ;

/*
so we have done the binary lifting implementation of the lca using this we can identify the lca 
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> timein ;
    vector<int> timeout ;
    int size ;
    vector<vector<int>> dp ;
    int timer ;
    public:
    graph(int n){
        vertices = n ;
        size = ceil(log2(n)) ;
        adjlist.resize(n) ;
        timein.resize(n) ;
        timeout.resize(n) ;
        dp.resize(n) ;
        for(int i = 0 ; i < n ; i++){
            dp[i].resize(size+1, 0) ;
        }
        timer = 0 ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs(int src, int parent){
        timein[src] = timer++ ;
        dp[src][0] = parent ;
        for(int i = 1 ; i <= size ; i++){
            dp[src][i] = dp[dp[src][i-1]][i-1] ;
        }

        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            dfs(node, src) ;
        }
        timeout[src] = timer++ ;
    }

    bool is_ancestor(int u, int v){
        bool ans = (timein[u] <= timein[v] && timeout[u] >= timeout[v]) ;
        return ans ;
    }

    int query(int u, int v){
        int ans = 0 ;
        u-- ;
        v-- ;
        if(is_ancestor(u, v)){
            ans = u + 1;
        }
        else if(is_ancestor(v, u)){
            ans = v + 1;
        }
        else{
            for(int i = size ; i >= 0 ; i--){
                if(!is_ancestor(dp[u][i], v)){
                    u = dp[u][i] ;
                }
            }
            ans = dp[u][0] + 1 ;
        }
        return ans ;
    }

    void preprocess(){
        dfs(0, 0) ;
        // cout<<size<<" "<<vertices<<endl ;
        // for(int i = 0 ; i < vertices ; i++){
        //   cout<<i+1<<": " ;
        //   for(int j = 0 ; j <= size ; j++){
        //     cout<<dp[i][j]+1<<" " ;
        //   }
        //   cout<<endl ;
        // }
        // cout<<endl;
    }
};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0 ;
    cin>>n ;
    int q = 0 ;
    cin>>q ;
    int m = n-1 ;
    graph g(n) ;
    int dest = 0 ;
    for(int i = 1 ; i <= m ; i++){
        cin>>dest ;
        g.add(i, dest-1) ;
    }

    g.preprocess() ;

    int a, b ;
    for(int i = 0 ; i < q ; i++){
        cin>>a>>b ;
        cout<<g.query(a,b)<<" " ;
    }
    cout<<endl ;
    return 0 ;
}