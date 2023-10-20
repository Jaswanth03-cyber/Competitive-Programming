#include <bits/stdc++.h>
using namespace std ;

/*
thing is that this is bellman ford but when there is a positive cycle and from that postive cycle if we can reach the destination then 
our distance to the destination can be infinite 

so if we do dfs in a graph from a src then whenever visited is true in the sense we can reach all those vertices from that src
in a reverse graph if we do bfs from a src and for whatever vertices revisited is true then we can reach that src from those all vertices in the original 
graph 

so here if there is a distance change after n-1th loop and if that vertex can be reachable from 1 and if we can reach dest from that vertex 
then distance can be unlimited so we make it -1 initial distance better keep it as -1e16 not LLONG_MIN 
as if there are any negative weights it we add then underflow. 
*/
typedef long long ll ;
typedef pair<int, ll> pi;
struct edge{
    int src ;
    int dest ;
    ll weight ;
    edge(int src, int dest, ll weight){
        this->src = src;
        this->weight = weight ;
        this->dest = dest ;
    }
};

class graph{
    int vertices ;
    vector<edge> edges ;
    vector<vector<pi>> adjlist ;
    vector<vector<pi>> revlist ;
    vector<bool> visited ;
    vector<bool> revisited ;
    public:
    graph(int n){
        vertices = n ;
        visited.resize(n, false) ;
        revisited.resize(n, false) ;
        adjlist.resize(n) ;
        revlist.resize(n) ;
    }

    void add(int src, int dest, ll weight){
        edges.push_back(edge(src, dest, weight)) ;
        adjlist[src].push_back({dest, weight}) ;
        revlist[dest].push_back({src,weight}) ;
    }

    void dfs(int src){
        if(visited[src]){
            return ;
        }
        visited[src] = true ;
        int size = adjlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            dfs(adjlist[src][i].first) ;
        }
    }
    void revdfs(int src){
        if(revisited[src]){
            return ;
        }
        revisited[src] = true ;
        int size = revlist[src].size() ;
        for(int i = 0 ; i < size ; i++){
            revdfs(revlist[src][i].first) ;
        }
    }

    void solve(){
        dfs(0) ;
        revdfs(vertices-1) ;
        vector<ll> distance(vertices, -1e16) ;
        int m = edges.size() ;
        distance[0] = 0 ;
        for(int i = 0 ; i < vertices - 1 ; i++){
            for(int i = 0 ; i < m; i++){
                int src = edges[i].src, dest = edges[i].dest ;
                ll weight = edges[i].weight ;
                if(distance[dest] < distance[src] + weight){
                    distance[dest] = distance[src] + weight ;
                }
            }
        }

        for(int i = 0 ; i < m ; i++){
                int src = edges[i].src, dest = edges[i].dest ;
                ll weight = edges[i].weight ;
                if(distance[dest] < distance[src] + weight){
                    if(visited[dest] && revisited[dest]){
                        cout<<-1<<endl ;
                        return ; 
                    }
                    distance[dest] = distance[src] + weight ;
                }
        }

        cout<<distance[vertices-1]<<endl ;
    }
};
int main(){

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n = 0, m = 0 ;
    cin>>n>>m ;

    int src = 0, dest = 0 ;
    ll cost = 0 ;
    graph g(n) ;
    for(int i = 0 ; i < m ; i++){
        cin>>src>>dest>>cost ;
        g.add(src-1, dest-1, cost) ;
    }

    g.solve() ;
    return 0 ;
}