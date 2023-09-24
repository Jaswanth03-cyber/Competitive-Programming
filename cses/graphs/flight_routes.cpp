#include <bits/stdc++.h>
using namespace std ;


/*
normally in dijkstra we will have a visited array which tells us when to stop or when to process inside the while loop 
here instead of visited we are having a distance 2D vector whose size is n*k where ith vector gives us the first k shortest paths distance 
from the soruce to i+1 node.
here instead if visited we are having distance if kth shortest path route distance of the node we are processing is less than d then no need to process
as we got k shortest distances than that, if not now we are processing the adjacent nodes of that node and updating the distances of those as there
are negative weight edges as distance[top-1][k-1] < d, if we add d + somecost but we already have shortest distance of that node(top-1) than that.

this ensures that loop will not go infinite.

if a node dest is adjacent to the node which is being processed if kth shortest distance of the dest is > the d + weight of the edge then we update it
and then sort the vector of the dest nodes distance vector as we are storing first k shortest distances so that distance[node-1][k-1] is the kth shortest
path until then so we are sorting that note that while pushing into the priority queue 
pq.push({distance[adjlist[top-1][i].first-1][k-1], adjlist[top-1].first}) this is wrong as the updated distance is sorted so the updates distance
may or may not be at the k-1th index. so thats why push direct value which we have updated or we can write that before sorting inside.
*/
typedef pair<int, long long> pii ;
typedef pair<long long, int> pi ;
class graph{
    int vertices ;
    vector<vector<pii>> adjlist ;
    public:
    graph(int n){
        vertices = n ;
        adjlist.resize(n) ;
    }

    void add(int src, int dest, long long cost){
        adjlist[src-1].push_back({dest, cost}) ;
    }
    void solve(int k){
        priority_queue<pi, vector<pi>, greater<pi>> pq ;
        vector<vector<long long>> distance(vertices, vector<long long>(k, LLONG_MAX)) ;
        distance[0][0] = 0 ;
        pq.push({0, 1}) ;
        int top = 0 ;
        long long d = 0 ;
        int size = 0 ;
        while(!pq.empty()){
            top = pq.top().second ;
            d = pq.top().first ;
            pq.pop() ;
            if(distance[top-1][k-1] < d){
                continue ;
            }
            size = adjlist[top-1].size() ;
            for(int i = 0 ; i < size ; i++){
                if(distance[adjlist[top-1][i].first-1][k-1] > d + adjlist[top-1][i].second){                    
                    distance[adjlist[top-1][i].first-1][k-1] = d + adjlist[top-1][i].second ;
                    sort(distance[adjlist[top-1][i].first-1].begin(), distance[adjlist[top-1][i].first-1].end()) ;
                    pq.push({d+adjlist[top-1][i].second, adjlist[top-1][i].first}) ;
                }
            }
        }

    for(int i = 0 ; i < k ; i++){
        cout<<distance[vertices-1][i]<<" " ;
    }
        cout<<endl ;
    }
};

int main(){

    cin.tie(NULL) ;
    cout.tie(NULL) ;
    ios_base::sync_with_stdio(false) ;

    int n = 0 ;
    cin>>n ;

    int m = 0 ;
    cin>>m ;

    int k = 0 ;
    cin>>k ;

    graph g(n) ;
    int src, dest ;
    long long cost ;
    for(int i  = 0 ; i < m; i++){
        cin>>src>>dest>>cost ;
        g.add(src, dest, cost) ;
    }

    g.solve(k) ;
    return 0 ;
}