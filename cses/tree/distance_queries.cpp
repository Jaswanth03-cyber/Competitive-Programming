#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> timein ;
    vector<int> timeout ;
    vector<ll> distance ;
    int timer ;
    int size ;
    vector<vector<int>> dp ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        timein.resize(n, 0) ;
        timeout.resize(n, 0) ;
        distance.resize(n, 0) ;
        timer = 0 ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs(int src, int parent, ll depth){
        timein[src] = timer++ ;
        distance[src] = depth ;
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
            dfs(node, src, depth+1) ;
        }
        timeout[src] = timer++ ;
    }

    bool is_ancestor(int u, int v){
        bool ans = (timein[u] <= timein[v] && timeout[u] >= timeout[v]) ;
        return ans ;
    }

    void preprocess(){
        size = ceil(log2(vertices)) ;
        dp.resize(vertices) ;
        for(int i = 0 ; i < vertices ; i++){
            dp[i].resize(size+1, -1) ;
        }
        dfs(0, 0, 0) ;
    }

    int lca(int u, int v){
        int ans = 0 ;
        if(is_ancestor(u, v)){
            ans = u ;
        }
        else if(is_ancestor(v, u)){
            ans = v ;
        }
        else{
            for(int i = size ; i >= 0 ; i--){
                if(!is_ancestor(dp[u][i], v)){
                    u = dp[u][i] ;
                }
            }
            ans = dp[u][0] ;
        }
        return ans ;
    }

    ll query(int a, int b){
        int lca_a_b = lca(a, b) ;
        ll ans = distance[a] + distance[b] - 2*distance[lca_a_b] ;
        return ans ;
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
    int src =0, dest = 0 ;
    graph g(n) ;
    for(int i = 1 ; i <= n-1 ; i++){
        cin>>src>>dest ;
        g.add(src-1, dest-1) ;
    }
    g.preprocess() ;
    int a, b ;
    for(int i = 0 ; i < q ; i++){
        cin>>a>>b ;
        cout<<g.query(a-1,b-1)<<endl ;
    }
    return 0 ;
}