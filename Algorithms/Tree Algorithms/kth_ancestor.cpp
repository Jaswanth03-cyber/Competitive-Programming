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
    int src =0, dest = 0 ;
    for(int i = 1 ; i <= n-1 ; i++){
        cin>>src>>dest ;
        g.add(src, dest) ;
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

/*
be carefull with indexing of elements here indexing goes from 0 to n-1 but node values are from 1 to n so after taking input while passing 
as parameter we are removing 1 and also while returning a value we are adding 1.
as usual dp[a][i] stores 2^ith ancestor of a so i is going from 0 till m where m = ceil(log2(n)) where n is the number of nodes.
so what we are doing is that we are writing k in a binary representation and also dp table is calculated same as we have done in lca one
for ex
succ(x, 11) = succ(succ(succ(x,8),2),1) so it is like taking y = dp[x][3] first then taking the z = dp[y][1] then taking dp[z][0] so this is how it 
is calculated 

see as src = 0 has no ancestors we are keeping it as -1 itself so we are not updating them and also when ever dp[src][i-1] is -1 no need to update 
we can break there because rest all will anyway be -1 and we can access dp[-1] also so thats why we are breaking. do not forget our dp number of columns is
m+1 not m and also in the query we are starting from m not 32 as our maximum index of dp table is m not 31 so not starting from 31, even though 
you start ig 31th bit is 0 so not an issue, so if a ith bit is set we have to move from a to its 2^ith ancestor and also before writing 
a = dp[a][i] do check if a is -1 or not there can be a case where in the previous iteration dp[a][i] might be -1 so to avoid run time error do check that
*/