#include <bits/stdc++.h>
using namespace std ;


/*
If we have the answer for some node (let's say node 1), how can we quickly find
the answer for its neighbours?

The key observation is that if we reroot the tree at node 1's neighbour (let's
say node 2), then

The depths of all nodes in node 2's subtree decrease by 1.
The depths of all nodes outside of its subtree increase by 1.


This gives us a nice way to transition from node 1's answer to node 2's answer
using only $n$ and the size of node 2's subtree! Observe that the change in the
answer is exactly n - 2(node 2's subtree size). in the subtree node itself is included


so do dfs at 0 now if reroot at its child 1 we can calculte for child1 using answer of 0 now reroot at child of child1 now using child1 we can compute for
child of child1. so on 

so in first dfs answer for the main starting root is caculated and stored in the dp[0] just adding depth of every node that will be the distance itself
in that dfs itself we are computing number of subordinates which we resuse later

in the second dfs as parent computation must be done before childs we have done the computation before calling to dfs itself. 

so for a node 
dp[child] = dp[parent] + n - 2*subordinates[child].
*/
typedef long long ll ;
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    vector<int> subordinates ;
    vector<ll> dp ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
        subordinates.resize(n, 0) ;
        dp.resize(n, 0) ;
    }

    void add(int src, int dest){
        adjlist[src].push_back(dest) ;
        adjlist[dest].push_back(src) ;
    }

    void dfs1(int src, int parent, int depth){
        int size = adjlist[src].size() ;
        dp[0] += depth ;
        subordinates[src] = 1 ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            dfs1(node, src, depth+1) ;
            subordinates[src] += subordinates[node] ;
        }
    }

    void dfs2(int src, int parent){
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            int node = adjlist[src][i] ;
            if(node == parent){
                continue ;
            }
            dp[node] = dp[src] + vertices - 2*subordinates[node] ;
            dfs2(node, src) ;
        }
    }

    void solve(){
        dfs1(0, 0, 0) ;
        dfs2(0, 0) ;
        for(int i = 0 ; i < vertices ; i++){
            cout<<dp[i]<<" " ;
        }
        cout<<endl ;
    }


};

int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;


    int n = 0 ;
    cin>>n ;
    int m = n-1;
    int src=0, dest=0 ;
    graph g(n) ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src-1, dest-1) ;
    }

    g.solve() ;
    return 0 ;
}