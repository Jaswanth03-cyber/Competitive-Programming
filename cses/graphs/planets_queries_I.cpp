#include <bits/stdc++.h>
using namespace std ;

class graph{
    int vertices ;
    vector<vector<int>> dp ;
    int m ;
    public:
    graph(int n){
        vertices = n ;
        m = 30 ;
        dp.resize(n, vector<int>(m, 0)) ;
    }

    void add(int src, int dest){
        dp[src][0] = dest ;
    }

    void preprocess(){
        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < vertices ; j++){
                dp[j][i] = dp[dp[j][i-1]][i-1] ;
            }
        }
    }

    int query(int src, int k){
        for(int i = 0 ; i < m ; i++){
            if(k&(1<<i)){
                src = dp[src][i] ;
            }
        }
        return src + 1 ;
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
    int dest = 0 ;
    graph g(n) ;
    for(int i = 0 ; i < n ; i++){
        cin>>dest ;
        g.add(i, dest-1) ;
    }
    g.preprocess() ;
    int a, k = 0;
    for(int i = 0 ; i < q ; i++){
        cin>>a>>k ;
        cout<<g.query(a-1, k)<<" " ;
    }
    cout<<endl ;
    return 0 ;
}