#include <bits/stdc++.h>
using namespace std ;

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
        dp.resize(n, vector<int>(m+1, 0)) // let all of them initialised to be 0 itself other than -1 to avoid run time errors.
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
        cout<<size<<" "<<vertices<<endl ;
        for(int i = 0 ; i < vertices ; i++){
          cout<<i+1<<": " ;
          for(int j = 0 ; j <= size ; j++){
            cout<<dp[i][j]+1<<" " ;
          }
          cout<<endl ;
        }
        cout<<endl;
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
    int dest = 0, src = 0;
    for(int i = 1 ; i <= m ; i++){
        cin>>src>>dest;
        g.add(src-1, dest-1) ;
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

/*
For each node we will precompute its ancestor above him, its ancestor two nodes above, its ancestor four above, etc. Let's store them in the 
array dp, i.e. dp[i][j] is the 2^j-th ancestor above the node i with i=1...N, j=0...ceil(log(N)). These information allow us to jump from any 
node to any ancestor above it in O(logN) time. We can compute this array using a DFS traversal of the tree. 

For each node we will also remember the time of the first visit of this node (i.e. the time when the DFS discovers the node), and the time 
when we left it (i.e. after we visited all children and exit the DFS function). We can use this information to determine in constant time if a 
node is an ancestor of another node.

Suppose now we received a query (u, v). We can immediately check whether one node is the ancestor of the other. In this case this node is already 
the LCA. If u is not the ancestor of v, and v not the ancestor of u, we climb the ancestors of u until we find the highest (i.e. closest to the 
root) node, which is not an ancestor of v (i.e. a node x, such that x is not an ancestor of v, but dp[x][0] is). We can find this node x in  
O(log N)  time using the array dp.

We will describe this process in more detail. Let L = ceil(log(N)). Suppose first that i = L. If dp[u][i] is not an ancestor of v, then we can 
assign u = dp[u][i] and decrement i. If dp[u][i] is an ancestor, then we just decrement i. Clearly after doing this for all non-negative i the 
node u will be the desired node - i.e. u is still not an ancestor of v, but dp[u][0] is.

Now, obviously, the answer to LCA will be dp[u][0] - i.e., the smallest node among the ancestors of the node u, which is also an ancestor of v.

So answering a LCA query will iterate i from ceil(log(N)) to 0 and checks in each iteration if one node is the ancestor of the other. 
Consequently each query can be answered in O(log N) .
*/