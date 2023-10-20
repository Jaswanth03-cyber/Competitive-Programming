#include <bits/stdc++.h>
using namespace std ;


/*
dp[s][i] denotes number of paths ending at index i travelling all the vertices in s just  only once and also i must be in s
so basically what we are doing is that basically we think like a distance only dp[node] = dp[top]+1 
so from what all vertices we can reach from to the a particular node using this we are solving the things.

dp[s][i] = sum(dp[s^(1<<i)][x]) where x belong to the list of nodes from which we can reach i and also x should be in s
*/
class graph{
    int vertices ;
    vector<vector<int>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest){
        adjlist[dest].push_back(src) ;
    }

    void solve(){
        vector<vector<int>> dp((1<<vertices), vector<int>(vertices, 0)) ;
        dp[1][0] = 1 ;
        int mod = 1e9 + 7 ;
        for(int i = 2 ; i < (1<<vertices) ; i++){
            if(!(i&1)){
                continue ;
            }
            if((i&(1<<(vertices-1))) && (i != (1<<vertices)-1)){
                continue ;
            }

            for(int j = 0 ; j < vertices ; j++){
                if(i&(1<<j)){
                    int size = adjlist[j].size() ;
                    for(int k = 0 ; k < size ; k++){
                        int node = adjlist[j][k] ;
                        if(i&(1<<node)){
                            dp[i][j] = (dp[i][j] + dp[i^(1<<j)][node])%mod  ;
                        }
                    }
                }
            }
        }

        cout<<dp[(1<<vertices) - 1][vertices-1]<<endl ;
    }
};



int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0, m = 0 ;
    cin>>n>>m ;

    graph g(n) ;
    int src=0, dest = 0 ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest ;
        g.add(src-1, dest-1) ;
    }

    g.solve() ;
    return 0 ;
}

/*
so we have to reach all the vertices just only once so in the adjlist we maintain from what all vertices we can reach to that node
now looping through all the sets 


our set must have first vertex as that is the starting point so if not there continue, if our set also has the last vertex then we must also have
all the other vertices otherwise no need to compute as we have to reach every vertex just once and our final destination is last vertex
if we do not write this if condition we will also calculate wasy where we can reach the last vertex but not visiting all the vertices
as lets say our set has {0,1,3,4,..n-1} so if we calculate for this set we for dp[s][n-1] in the inside second for loop when j = n-1 
we end up calculating number of ways we can reach this vertex(n-1) visiting all the vertices in the set(but set does not have all the vertices)

now looping through all the vertices(j) if we have this vertex in the set(here i) and now through all the vertices from which we can reach j
lets say k from which we can reach vertex j and also if this k is in the set then 
dp[s][i] += sum(dp[s-i][k])
as here dp[s][i] means ending at vertex i so dp[s-i][k] denotes number of ways to reach vertex k travelling through all the vertices in s except i 

so at the end we have to travel through all the vertices and have to end at vertex n so 
answer is dp[(1<<vertices)-1][vertices-1]


we can do this method for game routes also but there number of vertices are too many and also there we do not need the condition 
if((i&(1<<(vertices-1))) && (i != (1<<vertices)-1)){
    continue ;
}
as there is no rule that wee need to visit all the vertices before reaching the end vertex over there here we do hae
*/